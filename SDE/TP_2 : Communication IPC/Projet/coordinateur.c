#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include "shmem.h"
#include "semaphore.h"
#include "outils.h"

int id_bal;
int id_mutex;
int id_shmem;
int pid_generateur_traffic;

void quitter() {
	printf("Je meurs !\n");
	kill(pid_generateur_traffic, SIGQUIT);
	msgctl(id_bal, IPC_RMID, NULL);
	remove_semaphore(id_mutex);
	remove_shmem(id_shmem);
	exit(0);
}

int main() {
    /*créer la mémoire partagée qui contient : pid_coord, pid_feux, pid_generateur_traffic_prio, feu1, feu2, feu3, feu4, id_prio, depart_prio, arrivee_prio
    attacher la mémoire partagée en RW

    créer la boîte aux lettres
    attacher la boîte aux lettres

    créer le sémaphore mutex

    créer le processus fils Generateur_traffic_prio
    créer le processus fils Feux

    down(mutex)
    stocker les PID de Coordinateur et de Feux dans la mémoire partagée
    up(mutex)

    rediriger le signal SIGUSR1 vers la fonction alerter_feux*/
    
    signal(SIGINT, quitter);
    
    // Création des IPC
	key_t cle_bal = VAL_CLE_BAL;
	key_t cle_mutex = VAL_CLE_MUTEX;
	key_t cle_shmem = VAL_CLE_SHMEM;
	
	if((id_bal = msgget(cle_bal, 0666|IPC_CREAT)) == -1) {
		printf("Coordinateur : Impossible de créer la file de message.\n");
		quitter();
	}
	
	if((id_mutex = create_semaphore(cle_mutex)) == -1) {
		printf("Coordinateur : Impossible de créer le mutex.\n");
		quitter();
	}
	
	if((id_shmem = create_shmem(cle_shmem, shmem_size)) == -1) {
		printf("Coordinateur : Impossible de créer la mémoire partagée.\n");
		quitter();
	}
	
	// Attachement à la shmem
	int* pshmem;
	if((pshmem = attach_shmem(id_shmem)) == -1) {
		printf("Coordinateur : Impossible de s'attacher à la mémoire partagée.\n");
		quitter();
	}
	
	
	// Écriture du pid dans la shmem
	if(init_semaphore(id_mutex, 1) == -1) {
		printf("Coordinateur : Impossible d'initialiser le mutex.\n");
		quitter();
	}	
	down(id_mutex);
	printf("Test.\n");
	pshmem[0]=getpid();
	up(id_mutex);	
	
	int voitures[NB_VOITURES][3];
	int i;
	for(i = 0; i < NB_VOITURES; i++) {
		voitures[i][0] = 0;
		voitures[i][1] = 0;
		voitures[i][2] = 0;
	}
	
	int feux[4];
		
	ELEMVOITURE voiture;
	msgrcv(id_bal, &voiture, sizeof(ELEMVOITURE), TYPE_BAL, 0);
	pid_generateur_traffic = voiture.id;
			
	while (1) {
		int nb_voit_restantes = 0;
		
		// lire état des feux
		down(id_mutex);
		for(i = 0; i < 4; i++) {
			feux[i] = pshmem[i+3];
		}
		up(id_mutex);
		
		voiture.depart = NODIR;
		voiture.arrivee = NODIR;
		
		for(i = nb_voit_restantes; i < NB_VOITURES; i++) {
			if(voitures[i][0] == 0 && voitures[i][1] == 0 && voitures[i][2] == 0) {
				if(msgrcv(id_bal, &voiture, sizeof(ELEMVOITURE), TYPE_BAL, 0) != -1) {
					voitures[i][0] = voiture.id;
					voitures[i][1] = voiture.depart;
					voitures[i][2] = voiture.arrivee;
					printf("%d\n", voiture.id);
				}				
			}
		}
		
		//printf("%d : %d -> %d\n", voiture.id, voiture.depart, voiture.arrivee);
		//printf("%d : %d -> %d\n", voitures[0][0], voitures[0][1], voitures[0][2]);
		
		printf("----\n");
		for(i = 0; i < NB_VOITURES; i++) {
			printf("[%d] %d : %d -> %d\n", i, voitures[i][0], voitures[i][1], voitures[i][2]);
		}
		printf("----\n");
		
		feux[EST] = VERT;
		feux[OUEST] = VERT;
		
        for(i = 0; i < NB_VOITURES; i++) {
            if(feux[NORD] == VERT && feux[SUD] == VERT && feux[EST] == ROUGE && feux[OUEST] == ROUGE) {
                if((voitures[i][1] == NORD && (voitures[i][2] == SUD || voitures[i][2] == OUEST)) || (voitures[i][1] == SUD && (voitures[i][2] == NORD || voitures[i][2] == EST))) {
                    printf("Coordinateur : La voiture n°%d a pu franchir le carrefour %d->%d.\n", voitures[i][0], voitures[i][1], voitures[i][2]);
                    voitures[i][1] = 0;
                    voitures[i][2] = 0;
                    voitures[i][0] = 0;
                }
            } else if(feux[EST] == VERT && feux[OUEST] == VERT && feux[NORD] == ROUGE && feux[SUD] == ROUGE) {
                if((voitures[i][1] == EST && (voitures[i][2] == OUEST || voitures[i][2] == NORD)) || (voitures[i][1] == OUEST && (voitures[i][2] == EST || voitures[i][2] == SUD))) {
                    printf("Coordinateur : La voiture n°%d a pu franchir le carrefour %d->%d.\n", voitures[i][0], voitures[i][1], voitures[i][2]);
                    voitures[i][1] = 0;
                    voitures[i][2] = 0;
                    voitures[i][0] = 0;
                }
               // afficher état des voitures
            }
        }
        for(i = 0; i < NB_VOITURES; i++) {
            if(feux[NORD] == VERT && feux[SUD] == VERT && feux[EST] == ROUGE && feux[OUEST] == ROUGE) {
				if((voitures[i][1] == NORD && voitures[i][2] == EST) || (voitures[i][1] == SUD && voitures[i][2] == OUEST)) {
						printf("Coordinateur : La voiture n°%d a pu franchir le carrefour %d->%d.\n", voitures[i][0], voitures[i][1], voitures[i][2]);
						voitures[i][1] = 0;
						voitures[i][2] = 0;
						voitures[i][0] = 0;
				}
            } else if(feux[EST] == VERT && feux[OUEST] == VERT && feux[NORD] == ROUGE && feux[SUD] == ROUGE) {
				if((voitures[i][1] == EST && voitures[i][2] == SUD) || (voitures[i][1] == OUEST && voitures[i][2] == NORD)) {
					printf("Coordinateur : La voiture n°%d a pu franchir le carrefour %d->%d.\n", voitures[i][0], voitures[i][1], voitures[i][2]);
					voitures[i][1] = 0;
					voitures[i][2] = 0;
					voitures[i][0] = 0;
				}
			}
		}
        
        /* Mettre les voitures restantes au début du tableau
        for(i = 0; i < NB_VOITURES; i++) {
			if(voitures[i][0] != 0 && voitures[i][1] != 0 && voitures[i][2] != 0) {
				voitures[nb_voit_restantes][0] = voitures[i][0];
				voitures[nb_voit_restantes][1] = voitures[i][1];
				voitures[nb_voit_restantes][2] = voitures[i][2];
				nb_voit_restantes++;
			}	
		}*/
		
		for(i = 0; i < NB_VOITURES; i++) {
			voitures[i][0] = 0;
			voitures[i][1] = 0;
			voitures[i][2] = 0;
		}
	}
	
	return 0;
}

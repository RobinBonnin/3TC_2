#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include "shmem.h"
#include "outils.h"

void quitter() {
	printf("Je meurs !\n");
	exit(0);
}

int main() {
	signal(SIGQUIT, quitter);
	
    int id_bal;
	key_t cle_bal = VAL_CLE_BAL;
	
	
	if((id_bal = msgget(cle_bal, 0666)) == -1) {
		printf("Générateur traffic : Impossible d'accéder à la file de messages.\n");
		quitter();
	}


	ELEMVOITURE voiture;
	voiture.vtype = 1;
	
	// Envoi du PID au Coordinateur
	voiture.id = getpid();
	voiture.depart = 0;
	voiture.arrivee = 0;
	msgsnd(id_bal, &voiture, sizeof(ELEMVOITURE), 0);
	voiture.id = 0;
    
    srand(time(NULL));

	
    while(1) {
        voiture.depart = rand()%4+1;
        voiture.arrivee = rand()%4+1;

        while(voiture.depart == voiture.arrivee) {
            voiture.depart = rand()%4+1;
        }
		
		printf("Générateur traffic : La voiture n°%d vient de %d et veut aller vers %d.\n", voiture.id, voiture.depart, voiture.arrivee);		
		
		msgsnd(id_bal, &voiture, sizeof(ELEMVOITURE), 0);

        voiture.id++;
        sleep(1);
    }
    
    return(0);
}

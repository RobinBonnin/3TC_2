#include <stdio.h>
#include <stdlib.h>

#include "shmem.h"
#include "semaphore.h"


/*Generateur_traffic_prio {
        attacher le mutex
        attacher la mémoire partagée en RW
        récupérer le PID de Coordinateur

        int id_prio = 0;

        while(1) {
            int t = random(15..25)
            sleep(t)

            depart_prio = random(1..4)
            arrivee_prio = random(1..4)

            while(depart_prio == arrivee_prio) {
                depart_prio = random(1..4)
            }

            down(mutex)
            envoyer id_prio, depart_prio et arrivee_prio dans la mémoire partagée
            up(mutex)

            afficher "!!! PRIORITAIRE Génération traffic prio : La voiture `id_prio` vient de `depart` et veut aller vers `arrivee`. Je préviens le coordinateur."
            id_prio++
            envoyer un signal SIGUSR1 au Coordinateur
        }

        se détacher de la mémoire partagée */
        
int main() {
	int id_generateur_traffic_prio = getpid();
	int* pshmem;
	int id_coordinateur;
	
	id_shmem = open_shmem(VAL_CLE_SHMEM, shmem_size);
	pshmem = attach_shmem(id_shmem);
	
	id_coordinateur = pshmem[0];
	

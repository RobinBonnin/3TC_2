#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/sem.h>

#include "fonctions.h"

int ouvrirsem(key_t cle) {
	int idsem;
	
	if((idsem = semget(cle, 1, 0666|IPC_CREAT)) == -1) {
		printf("erreur d'ouverture\n");
		return -1;
		
	}
	
	return(idsem);
}

int supprimersem(int idsem) {
	if((semctl(idsem, 1, IPC_RMID, 0)) != 0) {
		printf("erreur destruction\n");
		return -1;
	}
	
	return 0;
}

void initsem(int idsem, int val) {
	if((semctl(idsem, 0,SETVAL, val)) == -1) {
		printf("erreur init\n");
		exit(1);
	}
}

void down(int idsem) {
	struct sembuf operation;
	operation.sem_num = 0;
	operation.sem_op = -1;
	operation.sem_flg = 0;
	
	if(semop(idsem, &operation, 1) == -1) {
		printf("erreur ouverture\n");
	}
}

void up(int idsem) {
	struct sembuf operation;
	operation.sem_num = 0;
	operation.sem_op = 1;
	operation.sem_flg = 0;
	
	if(semop(idsem, &operation, 1) == -1) {
		printf("erreur ouverture\n");
	}
}

void couperCheveux() {
	printf("Je coupe les cheveux d'un client.\n");
	sleep(2);
}

void obtenirCoupe() {
	printf("Je me fais couper les cheveux.\n");
}

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/sem.h>

#include "fonctions.h"

int main() {
	int CHAISES = 5;
	int attente = 0;
	
	key_t cleCoiffeur = 100;
	key_t cleClients = 101;
	key_t cleMutex = 102;
	int semCoiffeur = ouvrirsem(cleCoiffeur);
	int semClients = ouvrirsem(cleClients);
	int semMutex = ouvrirsem(cleMutex);
	
	initsem(semClients, CHAISES);
	
	down(semMutex);
	
	if(attente < CHAISES) {
		attente += 1;
		up(semClients);
		up(semMutex);
		down(semCoiffeur);
		obtenirCoupe();
		attente -= 1;
	} else {
		up(semMutex);
	}
	
	return 0;
}

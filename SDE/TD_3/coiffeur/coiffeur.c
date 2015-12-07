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
	key_t cleCoiffeur = 100;
	key_t cleClients = 101;
	key_t cleMutex = 102;
	int semCoiffeur = ouvrirsem(cleCoiffeur);
	int semClients = ouvrirsem(cleClients);
	int semMutex = ouvrirsem(cleMutex);
	
	initsem(semMutex, 0);
	initsem(semCoiffeur, 0);
	
	while(1) {
		down(semClients);
		down(semMutex);
		up(semCoiffeur);
		up(semMutex);
		couperCheveux();
	}
	
	return 0;
}

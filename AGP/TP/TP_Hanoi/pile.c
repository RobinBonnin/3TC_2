#include <stdio.h>

#include "pile_type.h"
#include "pile.h"

int error1(char* message) {
	printf("%s\n", message);
	exit(-1);
}

int Empiler (PILE* ppile, int val) {
	ELEMPILE* newElem;

	if((*ppile)->elem == 0) {
		(*ppile)->elem = val;
	} else if(val < (*ppile)->elem) {
		newElem = (ELEMPILE*) malloc(sizeof(ELEMPILE));
		if(newElem == NULL) {
			error1("Empiler: problème d'allocation mémoire");
			return 1;
		}
		newElem->elem = val;

		newElem->suivant = (*ppile);
		(*ppile) = newElem;
	} else {
		error1("Empiler: Opération impossible");
		return 1;
	}
	return 0;
}

int Depiler(PILE* ppile) {
	int val = 0;
	
	if((*ppile) != NULL) {
		val = (*ppile)->elem;
		(*ppile) = (*ppile)->suivant;
	} else {
		error1("Depiler: la pile est vide");
	}
	
	if((*ppile) == NULL) {
		(*ppile) = InitPile();
	}
	
	return val;
}

PILE InitPile() {
	PILE pile;
	
	pile = (PILE) malloc(sizeof(ELEMPILE));
	if(pile == NULL) {
		error1("InitPile: problème d'allocation mémoire");
	}
	pile->elem = 0;
	pile->suivant = NULL;
	
	return pile;
}

void afficherPile (PILE pile) {
	PILE curseur = pile;
	
	while(curseur != NULL) {
		printf("|%d|", curseur->elem);
		curseur = curseur->suivant;
	}
	printf("|--\n");
}

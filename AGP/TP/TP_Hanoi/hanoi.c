#include <stdio.h>

#include "pile.h"
#include "pile_type.h"

int deplacer(PILE* source, PILE* dest) {
	int piece = Depiler(source);
	Empiler(dest, piece);
	return 0;
}

int hanoi(PILE* depart, PILE* passage, PILE* arrivee, int N) { 
	if(N>1) {
		hanoi(depart, arrivee , passage, N-1);
		deplacer(depart, arrivee);
		hanoi(passage,depart ,arrivee , N-1);
	}
	else {
		deplacer(depart, arrivee);
	}
	
	return 0;
}

	


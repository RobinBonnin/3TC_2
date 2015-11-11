#include <stdio.h>
#include <stdlib.h>
#include "structure.h"


int main() {
	NODE* noeudTest; NODE* noeud2; NODE* noeud3; NODE* noeud4;
	FILE* dessin;
	noeud4=newNode(2,4,newNode(4,78,NULL,NULL),NULL);
	noeud2=newNode(3,40,NULL,noeud4);
	noeud3=newNode(2,3,noeud2,newNode(1,150,NULL,NULL));
	noeudTest=newNode(1,15,NULL,NULL);
	noeudTest=addNode(noeudTest,noeud3);
	noeud3=addNode(noeud3,newNode(1,35,NULL,NULL));
	noeudTest=addNode(noeudTest,newNode(4,125,NULL,NULL));
	printProgram(noeudTest);
	entetesvg(dessin);
	return(0);
}

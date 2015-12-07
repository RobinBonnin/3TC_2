#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"
#include "TODOarbre.h"

/*
int hauteurArbre(ARBRE arbre){
	ARBRE temp; 
	int n=0; int j=0;
	temp = arbre;
	if(temp->filsGauche !=NULL && temp->filsDroit !=NULL) {
		hauteurArbre(temp->filsGauche);
		hauteurArbre(temp->filsDroit);
	}
	if(temp->filsGauche !=NULL) {
		n=hauteurArbre(temp->filsGauche);
		n++;
	}
	else if (temp->filsDroit !=NULL) {
		hauteurArbre(temp->filsDroit);
		j++;
	}
	else {
		if(n>=j){
			return(n);
		}
		else{
			return(j);
		}
	}
}
*/

int max(a, b) {
	if(a > b)
		return a;
	else
		return b;
}

int hauteurArbre(ARBRE arbre) {
	if(arbre == NULL)
		return 0;
	else
		return 1 + max(hauteurArbre(arbre->filsDroit), hauteurArbre(arbre->filsGauche));
}


/*
int estEquilibre (ARBRE arbre){
	ARBRE temp;
	int n=0;
	int j=0; int test = 0;
	temp = arbre;
	n=hauteurArbre(temp->filsDroit);
	j=hauteurArbre(temp->filsGauche);
	if(temp->filsGauche !=NULL){
		test = estEquilibre(temp->filsGauche);
	}
	else if(temp->filsDroit !=NULL) {
		 test =estEquilibre(temp->filsDroit);
	}
	if(test==1) {
		return 1;
	}
	if(abs(j-n)<1){
		return 0;
	}
	else {
		return 1;
	}
}*/

int estEquilibre(ARBRE arbre) {
	if(arbre == NULL)
		return 1;
	
	int g = hauteurArbre(arbre->filsGauche);
	int d = hauteurArbre(arbre->filsDroit);
	
	if(g-d <= 1 && g-d >= -1) {
		return (estEquilibre(arbre->filsGauche) && estEquilibre(arbre->filsDroit));
	} else {
		return 0;
	}
}
	


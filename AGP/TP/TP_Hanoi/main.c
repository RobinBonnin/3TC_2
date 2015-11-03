#include <stdio.h>

#include "pile.h"
#include "pile_type.h"
#include "hanoi.h"

#define N 9
 
/*!
* \mainpage
* \brief petit programme de test utilisant le module hanoi et le module pile
**************************************************/    

/*!***********************************************
* \brief  le programme crée une pile de N élément et appelle Hanoi, il affiche le resultat puis teste une configuration d'erreur
**************************************************/    
 int main(int argc,char **argv)	
{PILE pile1,pile2,pile3;
 int elem,i;

 fprintf(stdout,"/********** test de pile d'entier *************\n");

  pile1=InitPile();
  pile2=InitPile();
  pile3=InitPile();
  for (i=N;i>0;i--)
    {
      elem=i;
      Empiler(&pile1,elem);
    }
    
  fprintf(stdout,"après mise en place d'un Hanoi de taille %d\n",N);
  afficherPile(pile1);
  afficherPile(pile2);
  afficherPile(pile3);

/*	for(i=0;i<N;i++){
		Depiler(&pile1);
		
	}
	for(i=N;i>0;i--){
		Empiler(&pile3,i);
	}*/
 
  hanoi(&pile1,&pile2,&pile3,N);

  fprintf(stdout,"après execution de hanoi \n");
  afficherPile(pile1);
  afficherPile(pile2);
  afficherPile(pile3);

 fprintf(stdout,"/********** test 2 *************\n");
 Empiler(&pile1,5);
 hanoi(&pile3,&pile2,&pile1,4);
 fprintf(stdout,"après execution de hanoi(4) \n");
 afficherPile(pile1);
 afficherPile(pile2);
 afficherPile(pile3);

 fprintf(stdout,"/********** test d'une erreur *************\n");
 hanoi(&pile3,&pile2,&pile1,4);
 fprintf(stdout,"/********** ne devrait pas arriver jusqu'ici *************\n");
 
 return 0;
}




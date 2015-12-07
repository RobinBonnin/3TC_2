#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"

//-----------------------------------------------
ARBRE nouvelArbre(int val, ARBRE fg, ARBRE fd)
{ARBRE temp;

  temp = (ARBRE) malloc(sizeof(NOEUD));
  temp->val=val;
  //on enracine fg et fd respectivement
  //aux noeuds fils de temp
  temp->filsGauche=fg;
  temp->filsDroit=fd;
  return(temp);
}

//-----------------------------------------------
void afficherArbre(ARBRE arbre, int decalage)
{int i;
 if (arbre!=NULL)
   { //parcours prefixe
     for (i=0;i<decalage;i++)
       fprintf(stdout," ");
     fprintf(stdout," +-");
     fprintf(stdout,"%4d\n",arbre->val);
     afficherArbre(arbre->filsDroit,decalage+4);
     afficherArbre(arbre->filsGauche,decalage+4);
   }
 else
   {
     for (i=0;i<decalage;i++)
       fprintf(stdout," ");
     fprintf(stdout,"*\n");
   }
}

//-----------------------------------------------
void libererArbre(ARBRE* arbre)
{
 if ( (*arbre) != NULL )
   { //parcours postfixe
     if ( (*arbre)->filsGauche != NULL )
       libererArbre( &((*arbre)->filsGauche) );
     if ( (*arbre)->filsDroit != NULL )
       libererArbre( &((*arbre)->filsDroit) );
     free( (*arbre) );
     (*arbre) = NULL;  
   }
}

#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"
#include "TODOarbre.h"

/*
 * \brief Programme qui teste les fonctions hauteurArbre
 * et estEquilibre devant etre implementees dans TODOarbre.h
 * \return 0 si les tests sont ok, 1 sinon
 * \see hauteurArbre estEquilibre 
 */
int main()
{
 
  ARBRE arbre, temp1,temp2;
  int nbok = 0; 
  int nb = 0;   

  //test hauteur 
  fprintf(stdout, "-------- test hauteur --------\n"); 

  //
  arbre = NULL; 

  //test hauteur arbre vide
  if (hauteurArbre(arbre) == 0) 
    nbok++;
  nb++;  
  fprintf(stdout, "(%d/%d)\n", nbok, nb);  

  //
  temp1 = nouvelArbre(10,NULL,NULL);

  //test hauteur arbre d'un noeud
  if (hauteurArbre(temp1) == 1) 
    nbok++;
  nb++;  
  fprintf(stdout, "(%d/%d)\n", nbok, nb);  

  //
  temp2 = nouvelArbre(20,NULL,NULL);
  arbre = nouvelArbre(30,temp1,temp2);

  //test hauteur arbre d'un noeud avec deux fils
  if (hauteurArbre(arbre) == 2) 
    nbok++;
  nb++;  
  fprintf(stdout, "(%d/%d)\n", nbok, nb);  

  ///////////////////////
  temp1=nouvelArbre(40,NULL,NULL);
  temp2=nouvelArbre(50,NULL,NULL);
  temp1=nouvelArbre(60,temp1,temp2);
  arbre=nouvelArbre(70,arbre,temp1);
  temp2=nouvelArbre(80,NULL,NULL);
  arbre=nouvelArbre(90,arbre,temp2);

  //test hauteur arbre normal
  if (hauteurArbre(arbre) == 4) 
    nbok++;
  nb++;  
  fprintf(stdout, "(%d/%d)\n", nbok, nb);

  //liberer arbre
  libererArbre(&arbre);
  if (arbre == NULL) 
    nbok++;
  nb++;  
  fprintf(stdout, "(%d/%d)\n", nbok, nb);  
  //NB: il n'y a rien d'autre a liberer
  //car toutes les donnees allouees dans 
  //le tas ont des pointeurs dans arbre

  //test equilibre
  fprintf(stdout, "-------- test equilibre --------\n");

  //test equilibre arbre vide
  if (estEquilibre(arbre) == 1)
    nbok++;
  nb++;
  fprintf(stdout, "(%d/%d)\n", nbok, nb);

  ///////////////////////
  temp1 = nouvelArbre(10,NULL,NULL);

  //test equilibre arbre d'un noeud
  if (estEquilibre(temp1) == 1)
    nbok++;
  nb++;
  fprintf(stdout, "(%d/%d)\n", nbok, nb);

  ///////////////////////
  temp2 = nouvelArbre(20,NULL,NULL);
  arbre = nouvelArbre(30,temp1,temp2);

  //test equilibre arbre d'un noeud avec deux fils
  if (estEquilibre(arbre) == 1)
    nbok++;
  nb++;
  fprintf(stdout, "(%d/%d)\n", nbok, nb);

  /* /////////////////////// */
  /* temp1=nouvelArbre(40,NULL,NULL); */
  /* temp2=nouvelArbre(50,NULL,NULL); */
  /* temp1=nouvelArbre(60,temp1,temp2); */
  /* arbre=nouvelArbre(70,arbre,temp1); */
  /* temp2=nouvelArbre(80,NULL,NULL); */
  /* arbre=nouvelArbre(90,arbre,temp2); */

  /* //test equilibre autre arbre */
  /* if (estEquilibre(arbre) == 0) */
  /*   nbok++; */
  /* nb++; */
  /* fprintf(stdout, "(%d/%d)\n", nbok, nb); */

  //liberer arbre
  libererArbre(&arbre);
  if (arbre == NULL)
    nbok++;
  nb++;
  fprintf(stdout, "(%d/%d)\n", nbok, nb);

  ///////////////////////
  //test equilibre sur arbre equilibre de hauteur 3
  temp1=nouvelArbre(3,NULL,NULL);
  temp2=nouvelArbre(3,NULL,NULL);
  arbre=nouvelArbre(3,NULL,NULL); 
  temp1=nouvelArbre(2,temp1,temp2);
  arbre=nouvelArbre(2,arbre,NULL); 
  arbre=nouvelArbre(1,temp1,arbre);

  if ( (estEquilibre(arbre) == 1)&&(hauteurArbre(arbre)==3) )
    nbok++;
  nb++;
  fprintf(stdout, "(%d/%d)\n", nbok, nb);

  //afficher arbre
  afficherArbre(arbre, 0);

  //liberer arbre
  libererArbre(&arbre);
  if (arbre == NULL)
    nbok++;
  nb++;
  fprintf(stdout, "(%d/%d)\n", nbok, nb);

  ///////////////////////
  //test equilibre sur arbre non equilibre
  //ayant pourtant deux sous-arbres enracine 
  //aux fils gauche et droit de meme hauteur
  temp1=nouvelArbre(4,NULL,NULL);
  temp2=nouvelArbre(4,NULL,NULL);
  temp1=nouvelArbre(3,temp1,NULL);
  temp2=nouvelArbre(3,temp2,NULL);
  temp1=nouvelArbre(2,temp1,NULL);
  temp2=nouvelArbre(2,temp2,NULL);
  arbre=nouvelArbre(1,temp1,temp2);

  if ( (estEquilibre(arbre) == 0)&&(hauteurArbre(arbre)==4) )
    nbok++;
  nb++;
  fprintf(stdout, "(%d/%d)\n", nbok, nb);

  //afficher arbre
  afficherArbre(arbre, 0);

  //liberer arbre
  libererArbre(&arbre);
  if (arbre == NULL)
    nbok++;
  nb++;
  fprintf(stdout, "(%d/%d)\n", nbok, nb);
  
  ///////////////////////
  //test equilibre sur arbre non equilibre
  //ayant pourtant deux sous-arbres equilibre
  //mais pas de meme hauteur
  //premier sous-arbre equilibre de hauteur 3
  temp1=nouvelArbre(3,NULL,NULL);
  temp2=nouvelArbre(3,NULL,NULL);
  arbre=nouvelArbre(3,NULL,NULL); 
  temp1=nouvelArbre(2,temp1,temp2);
  arbre=nouvelArbre(2,arbre,NULL); 
  arbre=nouvelArbre(1,temp1,arbre);
  //second sous-arbre equilibre de hauteur 1
  temp1=nouvelArbre(11,NULL,NULL); 
  //arbre complet
  arbre=nouvelArbre(0,arbre,temp1); 

  if ( (estEquilibre(arbre) == 0) )
    nbok++;
  nb++;
  fprintf(stdout, "(%d/%d)\n", nbok, nb);

  //afficher arbre
  afficherArbre(arbre, 0);

  //liberer arbre
  libererArbre(&arbre);
  if (arbre == NULL)
    nbok++;
  nb++;
  fprintf(stdout, "(%d/%d)\n", nbok, nb);

  /////////////////////////////////////////////
  //conclusion
  if (nbok == nb) 
    {
      fprintf(stdout, "PASSED\n"); 
      return 0;
    }
  else
    {
      fprintf(stdout, "FAILED\n"); 
      return 1; 
    }
}



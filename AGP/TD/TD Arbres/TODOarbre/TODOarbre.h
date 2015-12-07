#ifndef TODO_ARBRE_H
#define TODO_ARBRE_H

#include "arbre_type.h"

/**
* \brief Fonction qui calcule la hauteur d'un arbre
* binaire donne en parametre 
* \param arbre un arbre binaire
* \return la hauteur, ie. le nombre de noeuds du plus grand 
* chemin reliant la racine a une feuille de l'arbre 
*/
int hauteurArbre(ARBRE arbre);

/**
* \brief Fonction qui indique si l'arbre binaire passe en 
* parametre est equilibre ou non, ie. si la hauteur de son 
* sous-arbre gauche est celle de son sous-arbre droit a un
* pres et ces deux sous-arbres sont equilibres. 
* \param arbre un arbre binaire
* \return 1 s'il est equilibre, 0 sinon.  
*/
int estEquilibre (ARBRE arbre);

#endif

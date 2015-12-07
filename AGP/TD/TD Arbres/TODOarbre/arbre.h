#ifndef arbre_h
#define arbre_h

#include "arbre_type.h"

/**
* \brief Fonction qui cree un nouvel arbre binaire d'entiers
* a partir d'une nouvelle valeur et de deux sous-arbres. 
* \param val un entier
* \param fg le sous-arbre gauche
* \param fd le sous-arbre droit
* \return le nouvel arbre
*/
ARBRE nouvelArbre(int val, ARBRE fg, ARBRE fd);

/**
* \brief Fonction qui affiche un arbre sur la sortie standard
* a l'aide d'un parcours prefixe.  
* \param arbre un arbre
* \param decalage un entier qui donne le nombre d'espaces a 
* inserer avant l'affichage de l'entier situe a la racine de 
* l'arbre donne en parametre
*/
void afficherArbre(ARBRE arbre, int decalage);

/**
* \brief Fonction qui supprime tous les noeuds d'un arbre
* (en liberant la memoire associee a ces noeuds), a l'aide 
* d'un parcours postfixe.  
* \param arbre un arbre
*/
void libererArbre(ARBRE* arbre); 

#endif

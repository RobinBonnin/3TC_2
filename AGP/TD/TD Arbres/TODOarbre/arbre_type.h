#ifndef arbre_type_h
#define arbre_type_h

/*! \brief structure de noeud d'un arbre binaire d'entiers */
struct model_noeud
{
  int val; //valeur de l'entier
  struct model_noeud *filsGauche; //pointeur vers le fils gauche
  struct model_noeud *filsDroit; //pointeur vers le fils droit
};

/*! \brief redefinition de la structure de noeud d'un arbre binaire d'entiers */
typedef struct model_noeud NOEUD;

/*! \brief definition d'un arbre binaire d'entiers comme un pointeur vers un noeud */
typedef NOEUD *ARBRE;

#endif

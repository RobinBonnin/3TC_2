#include "triRapide.h"

//----------------------------------------------------
int segmentation(int d[], int N,  int debut, int fin)
{ 
  int i, valeurPivot, pivot;

  #ifdef MY_DEBUG_MODE
  fprintf(stderr,"Appel segmentation(%d,%d)\n",debut,fin);
  #endif

  //on choisit la valeur de pivot au hasard : la premiere valeur
  valeurPivot = d[debut]; 
  //pivot verifie la propriete suivante: 
  //tous les entiers entre debut et pivot sont inferieurs a
  //valeurPivot, tous les entiers entre place+1 et i sont 
  //superieurs a valeurPivot
  pivot = debut;
  
  for (i = debut+1; i <= fin; i++)
    {
      if (d[i] <= valeurPivot) /* la valeur est bien placee */
	{ 
	  pivot++;
	  permutation(d,i,pivot);
	}
    }

  //on place la valeurPivot (=d[debut]) a la position pivot 
  permutation(d, debut, pivot);

  return pivot;
}

//----------------------------------------------------
void triRapide2(int d[], int N, int debut, int fin)
{
  int place;

  #ifdef MY_DEBUG_MODE
  fprintf(stderr,"Appel SortQuick(%d,%d)\n",debut,fin);
  #endif

  //on lance le tri si le tableau n'est pas vide : 
  //les indices ne se croisent pas 
  if(debut<fin) 
    {
      place = segmentation(d, N, debut, fin);
      //d est alors tel que d[a..place-1] <= d[place] < d[place+1..b]
      //il suffit alors de trier les deux sous-tableaux
      triRapide2(d, N, debut, place-1);
      triRapide2(d, N, place+1, fin);
    }
}

//---------------------------------------------
void triRapide(int d[], int N)
{
  triRapide2(d, N, 0, N-1); 
}

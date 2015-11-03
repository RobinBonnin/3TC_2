#include "triBulle.h"

void triBulle(int T[], int N)
{
  int i; //indice de boucle
  int debut, fin; //premier et dernier indice
  int euPermutation; //1 s'il y a eu au moins une permutation, 0 sinon. 

  debut = 0; 
  fin = N-1; 
  euPermutation = 1; 
  do {
    euPermutation = 0; 
    for (i = debut+1; i <= fin; i++)
      {
	if (T[i-1] > T[i])
	  { //si non trie
	    permutation(T, i-1, i); 
	    euPermutation = 1; 
	  }
      }

  } while (euPermutation); 

}

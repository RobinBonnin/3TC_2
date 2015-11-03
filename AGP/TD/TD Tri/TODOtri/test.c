#include <stdio.h>

#define MY_DEBUG_MODE

#include "triBulle.h"
#include "triFusion.h"
#include "triRapide.h"

/*!
************************************************
* \brief Teste si le tableau t de n entiers 
* est trie par ordre croissant
* \param t un tableau de n entiers
* \param n taille du tableau t
* \return 1 si t est trie, 0 sinon
**************************************************/    
int testTri(int t[], int n)
{
  int i; 
  int estTrie; //1 si le tableau est trie, 0 sinon

  estTrie = 1; 
  for (i=1;i<n;i++)
    {
      if (t[i] < t[i-1])
	estTrie = 0;  
    }
  if (estTrie)
    printf("PASSED");
  else
    printf("FAILED"); 
  printf("\n");

  return estTrie ? 1 : 0;
}

/*!
 * \brief Programme qui teste si les resultats
 * de differents algorithmes de tri sont corrects
 * \see testTri
*/
int main(int argc,char **argv)
{
  int estTrie; //1 si les tableaux sont tries, 0 sinon
  estTrie = 1; 

 printf("************************ Tri bulle ********\n");
  { //test 1
    int t[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  
    triBulle(t, 10);
    estTrie = estTrie && testTri(t, 10); 
  }
  { //test 2
    int t[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; 
    triBulle(t, 10);
    estTrie = estTrie && testTri(t, 10); 
  }
  { //test 3
    int t[10] = {9, 1, 8, 2, 7, 3, 6, 4, 5, 10}; 
    triBulle(t, 10);
    estTrie = estTrie && testTri(t, 10); 
  }

  if (estTrie)
    {
      printf("************************ Tri rapide *******\n");
      { //test 1
	int t[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  
	triRapide(t, 10);
	estTrie = estTrie && testTri(t, 10); 
      }
      { //test 2
	int t[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; 
	triRapide(t, 10);
	estTrie = estTrie && testTri(t, 10); 
      }
      { //test 3
	int t[10] = {9, 1, 8, 2, 7, 3, 6, 4, 5, 10}; 
	triRapide(t, 10);
	estTrie = estTrie && testTri(t, 10); 
      }
    }

  if (estTrie)
    {
      printf("************************ Tri fusion *******\n");
      { //test 1
	int t[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  
	triFusion(t, 10);
	estTrie = estTrie && testTri(t, 10); 
      }
      { //test 2
	int t[11] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1,11}; 
	triFusion(t, 11);
	estTrie = estTrie && testTri(t, 11); 
      }
      { //test 3
	int t[10] = {9, 1, 8, 2, 7, 3, 6, 4, 5, 10}; 
	triFusion(t, 10);
	estTrie = estTrie && testTri(t, 10); 
      }
    }


  return estTrie ? 0 : 1;
}


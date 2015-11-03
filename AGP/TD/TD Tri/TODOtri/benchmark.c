#include "ioHelpers.h"

#include "triBulle.h"
#include "triFusion.h"
#include "triRapide.h"

#define TAILLE_CHAINE 20 /* taille d'une chaine de caractères */
#define TAILLE 1000

#include <time.h>

/*!
 * \brief Procedure qui appelle la fonction tri sur le tableau t
 * de taille n et affiche le temps d'execution sur la sortie standard. 
 * \param t tableau a trier
 * \param n taille du tableau t
 * \param tri fonction de tri ayant 2 parametres: 
 * - le tableau a trier, 
 * - sa taille
 */
void runWithTimeDisplay(int t[], int n, void (*tri)(int[], int))
{
  struct timeval ta;
  struct timeval tb;

  gettimeofday(&ta,0);

  //appel de la fonction de tri
  tri(t,n);

  gettimeofday(&tb,0);

  //calcul et affichage du temps d'execution
  int time = (int) (tb.tv_usec-ta.tv_usec); 
  if (time < 0) time = 0; 
  printf("%d ", time);
}

/*!
 * \brief manuel d'utilisation de la fonction main 
 * \param  nomProg le nom de l'executable
 */
void usage( char nomProg[TAILLE_CHAINE] )
{
  fprintf(stderr,"usage: %s option (fichier)\n",nomProg);
  fprintf(stderr,"option: '0' pour N entiers tries dans l'ordre croissant\n");
  fprintf(stderr,"        '9' pour N entiers tries dans l'ordre decroissant\n");
  fprintf(stderr,"        'd' pour lire les N entiers dans 'fichier'\n");
  fprintf(stderr,"fichier: donnees a trier (doit etre specifie apres l'option 'd')\n");
}

/*!
 * \brief Programme qui affiche a l'ecran le temps de calcul 
 * d'un tri a bulle, d'un tri fusion, d'un tri rapide pour tous
 * les sous-tableaux d'entiers allant de la position 0 a la 
 * position i (0 <= i < N). 
 * Il y a plusieurs types de donnees a trier possibles: 
 * - '0' les N entiers par ordre croissant
 * - '9' les N entiers par ordre decroissant
 * - 'd' N entiers lu dans un fichier dont le nom est donne
 * en parametre. 
 * \param argc nombre de parametres
 * \param argv tableau des parametres
 * \see usage
*/
int main(int argc,char **argv)
{
  int i, k; //indices de boucle
  int data[TAILLE]; /* tableau de donnee */
  char TypeTri[1]; /* type de donnees choisies : '0', '9', ou 'd' */
  char NomFichier[TAILLE_CHAINE]; /* nom du fichier contenant le tableau a trier */
  char nomProg[TAILLE_CHAINE];/* utilise pour recuperer le nom de l'executable*/

  // nom de l'executable 
  strcpy(nomProg,argv[0]);

  if (argc < 2)
    { 
      usage(nomProg); 
      return 1; 
    }

  // type de tri ('0', '9', 'd')
  TypeTri[0]=argv[1][0];

  switch (TypeTri[0])
    {
    case '0' : 
      //ordre croissant
      for (i = 0; i < TAILLE; i++)
	{
	  data[i] = i; 
	}
      break;
    case '9' : 
      //ordre decroissant
      for (i = 0; i < TAILLE; i++)
	{
	  data[i] = TAILLE -1 - i; 
	}
      break;
    case 'd' : 
      
      if (argc < 3)
	{
	  usage(nomProg); 
	  return 1; 
	}

      // Nom du fichier de donnees
      strcpy(NomFichier,argv[2]);

      // Lecture des donnees
      ReadData(NomFichier, data,TAILLE);

      break;
    default : 
      usage(nomProg);
      return 1;
    }

  /* printf("============= Donnees =====================\n"); */
  /* PrintTable(data, TAILLE); */

  printf("# Taille et temps des tris bulle, fusion, rapide \n");  
  //pour tous les sous-tableaux de 1 a i
  //declencher les tris 
  for (i = 100; i < TAILLE; i++)
    {
      int data2[i]; //sous-tableau
      
      printf("%d ", i); //taille des donnees

      //tri bulle
      //copie du sous-tableau data2
      for (k = 0; k < i; k++)
	  data2[k] = data[k]; 
      runWithTimeDisplay(data2, i, triBulle); 

      //tri fusion
      //copie du sous-tableau data2
      for (k = 0; k < i; k++)
	  data2[k] = data[k];  
      runWithTimeDisplay(data2, i, triFusion); 

      //tri rapide
      //copie du sous-tableau data2
      for (k = 0; k < i; k++)
	  data2[k] = data[k]; 
      runWithTimeDisplay(data2, i, triRapide); 

      printf("\n"); 
    }


  return 0;
}


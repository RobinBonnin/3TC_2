#include "ioHelpers.h"

//#define MY_DEBUG_MODE decommente pour voir les appels recursifs

#include "triBulle.h"
#include "triFusion.h"
#include "triRapide.h"

#define TAILLE_CHAINE 20 /* taille d'une chaine de caractères */
#define TAILLE 1000

/*!
 * \brief manuel d'utilisation de la fonction main 
 * \param  nomProg le nom de l'executable
 */
void usage( char nomProg[TAILLE_CHAINE] )
{
  fprintf(stderr,"usage: %s option fichier\n",nomProg);
  fprintf(stderr,"option: f  pour tri fusion\n");
  fprintf(stderr,"        q  pour tri rapide\n");
  fprintf(stderr,"        b  pour tri a bulle\n");
  fprintf(stderr,"fichier: donnees a trier\n");
}

/*!
 * \brief Programme de tri par differents algorithmes
 *  suivant l'argument sur la ligne de commande (f, q ou b). 
 * Le programme lance un tri fusion, rapide ou a bulle sur 
 * le fichier donne en deuxième argument. Le resultat du tri
 * et le temps d'execution sont affiches a l'ecran. 
 * \param argc nombre de parametres
 * \param argv tableau des parametres
 * \see usage
*/
int main(int argc,char **argv)
{

  int data[TAILLE]; /* tableau de donnee et tableau auxiliaire de traitement */
  char TypeTri[1]; /* type de tri choisi : 'f', 'q', ou 'b' */
  char NomFichier[TAILLE_CHAINE]; /* nom du fichier contenant le tableau a trier */
  char nomProg[TAILLE_CHAINE];/* utilise pour recuperer le nom de l'executable*/

  struct timeval ta;
  struct timeval tb;

  // nom de l'executable 
  strcpy(nomProg,argv[0]);

  /* Il faut le type de tri (f, b  ou q) et le nom du fichier donnees */
  if (argc != 3)
    { 
      usage(nomProg); 
      return 1; 
    }

  //type de tri (b f ou q)
  TypeTri[0]=argv[1][0];
  // nom du fichier de donnees
  strcpy(NomFichier,argv[2]);

  /* Lecture des donnees */
  ReadData(NomFichier, data,TAILLE);

  //PrintTable(data,N);

  //La fonction gettime of day de la bibliotheque time.h
  //renvoie un structure de type timeval contenant le temps 
  //ecoule depuis le 1er Janvier 1970
  gettimeofday(&ta,0);

  /* On declanche le tri selon le type demande */
  switch (TypeTri[0])
    {
    case 'f' : 
      triFusion(data,TAILLE);
      break;
    case 'q' : 
      triRapide(data,TAILLE);
      break;
    case 'b' : 
      triBulle(data,TAILLE);
      break;
    default : 
      usage(nomProg);
      return 1;
    }

  gettimeofday(&tb,0);

  printf("=============Fichier Trie=====================\n");
  PrintTable(data,TAILLE);

  printf("Temps (micro) = %d\n",(int) (tb.tv_usec-ta.tv_usec));

  return 0;
}


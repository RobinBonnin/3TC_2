#ifndef TRIRAPIDE_H
#define TRIRAPIDE_H

#include "permutation.h"

/*!
 * \brief Segmente un intervalle (entre les positions debut et fin) 
 * en deux sous-intervalles dont les entiers se trouvent de part et 
 * d'autre d'un entier pivot. La fonction choisit un entier (le premier
 * rencontre) et rearrange les elements du tableau d de telle sorte que :
 * d[debut..pivot-1] <= d[pivot] < d[pivor+1..fin] 
 * \param d un tableau de N entiers non necessairement trie
 * \param N la taille du tableau
 * \param debut l'indice inferieur de l'intervalle a trier 
 * \param fin l'indice superieur de l'intervalle a trier 
 * \pre 0 <= debut < fin < N 
 * \post d[debut..pivot-1] <= d[pivot] < d[pivor+1..fin]
 * \return pivot la position de l'entier pivot
 */
int segmentation(int d[], int N,  int debut, int fin);


/*!
 * \brief Trie le tableau d entre les indices debut et fin, 
 selon l'algorithme de tri rapide 
 * \param d un tableau de N entiers non necessairement trie
 * \param N la taille du tableau
 * \param debut l'indice inferieur de l'intervalle a trier 
 * \param fin l'indice superieur de l'intervalle a trier 
 * \pre 0 <= debut < fin < N 
 * \post d est trie entre debut et fin 
 * \see segmentation
 */
void triRapide2(int d[], int N, int debut, int fin);

/*!
 * \brief Trie le tableau d de taille N, 
 selon l'algorithme de tri rapide 
 * \param d un tableau de N entiers non necessairement trie
 * \param N la taille du tableau
 * \post d est trie
 * \see triRapide2
 */
void triRapide(int d[], int N);

#endif

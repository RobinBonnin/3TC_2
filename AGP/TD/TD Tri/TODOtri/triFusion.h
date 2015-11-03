#ifndef TRIFUSION_H
#define TRIFUSION_H

/*!
************************************************
* \brief remplit un tableau trie de 2N elements en 
* fusionnant deux tableaux de N elements tries
* \param T un tableau de N entiers
* \param N taille du tableau T
* \param S un deuxième tableau de N entiers
* \param M taille du tableau S
* \param TS un tableau de N+M entiers issu de la fusion
* des deux premiers tableaux.
* \warning Le tableau TS est deja alloue mais vide
**************************************************/    
void fusion(int T[], int N, int S[], int M, int TS[]);

/*!
 * \brief Trie recursivement le tableau d, 
 * selon l'algorithme du tri fusion. 
 * \param d un tableau de N entiers
 * \param N la taille du tableau
 * \see fusion 
 */ 
void triFusion(int d[], int N);

#endif

#ifndef IOHELPERS_H
#define IOHELPERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/timeb.h>
#include <sys/time.h>
#include <unistd.h>

/*!
 * \brief Affiche a l'ecran les l premieres valeurs du tableau t 
 * \param t un tableau d'entier de taille N
 * \param l un entier (inférieur à N)
 * \pre  l <= N
 */ 
void PrintTable(int t[],int l);

/*!
 * \brief Lit les l premiers entiers contenus dans le fichier NomFic 
 * et les place dans le tableau t
 * \param NomFic une chaine de caractère contenant le nom du fichier à lire
 * \param t un tableau de taille N 
 * \param l  un entier (l <= N)
 * \pre le fichier contient au moins l valeurs entieres, Le tableau t de 
 taille N est deja alloué et l <= N
*/ 
void ReadData(char *NomFic, int t[],int l); 

#endif

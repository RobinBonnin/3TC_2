#ifndef __OUTILS_H_OUTILS__
#define __OUTILS_H_OUTILS__

#include <stdio.h>
#include <stdlib.h>

// Clés des différentes IPC
#define VAL_CLE_BAL 12 // Boîte aux lettres voitures
#define VAL_CLE_SHMEM 20 // Mémoire partagée
#define VAL_CLE_MUTEX 21 // Mutex

#define TYPE_BAL 1
#define NB_VOITURES 3

// Direction des voitures
#define NODIR 0 // aucune direction
#define NORD 1
#define EST 2
#define SUD 3
#define OUEST 4

// État des feux
#define VERT 1
#define ROUGE 0

// Structure des messages de la boîte aux lettres contenant les voitures
struct model_voiture {
	long vtype;
	int id;
	int depart;
	int arrivee;
};

typedef struct model_voiture ELEMVOITURE;
typedef ELEMVOITURE* VOITURE; 

// Variables globales pour les véhicules prioritaires
int depart_prio = 0;
int arrivee_prio = 1;

// Variable globale pour la taille de la mémoire partagée
int shmem_size = sizeof(int)*10;

#endif

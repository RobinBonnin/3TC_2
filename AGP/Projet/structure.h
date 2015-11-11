#include <stdio.h>
#include <stdlib.h>

typedef struct NODE { //Structure d'un noeud de commande
 int instruction;
 int val;
 struct NODE* sousProgramme;
 struct NODE* instructionSuivant;
}NODE;

typedef struct POINT POINT ; // Structure d'un point pour SVG
struct POINT{
	
	double direction;
	double x;
	double y;
	
};





NODE* newNode (int inst,int Val, NODE* sousProg,NODE* instSuivant); // Création du noeud avec les instructions


NODE* addNode (NODE* noeudSource,NODE* programme); //Ajouter un neoud à noeudSource

void printProgram(NODE* programme);

POINT *creer_point(double x, double y, double direction);

static NODE* root;

void lancement();

POINT *pointfinligne(POINT* origine, int val); //Point de destination après création d'une ligne : nouvelle origine

void generersvg(NODE* noeud, FILE* fichier, POINT* origine);

	
	

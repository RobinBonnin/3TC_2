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



/**
* \brief Fonction qui crée un noeud avec les instructions en paramètres
* \param inst la valeur en entier de l'instruction ( 1 : FORWARD, 2 : REPEAT, LEFT : 3 RIGHT : 4 ) 
* \param Val la valeur associée à l'instruction ( angle en degrés ou avancement )
* \param sousProg le sousProgramme dans le cas d'un REPEAT
* \return le nouveau noeud
*/

NODE* newNode (int inst,int Val, NODE* sousProg,NODE* instSuivant); // Création du noeud avec les instructions


/**
* \brief Fonction qui ajoute un noeud avec les instructions en paramètres au noeud déjà existant
* \param noeudSource le noeud auquel va être rattaché le noeud
* \param programme le programme qui va être dans le noeud rattaché
* \return le nouveau noeud
*/

NODE* addNode (NODE* noeudSource,NODE* programme); //Ajouter un neoud à noeudSource

/**
* \brief Fonction qui affiche le programme sur le terminal
* \param programme le programme qui va être affiché
* \return void
*/

void printProgram(NODE* programme);

/**
* \brief Fonction qui créer un point dans le svg
* \param x abscisse du point
* \param y ordonée du point
* \return le point
*/

POINT *creer_point(double x, double y, double direction);

static NODE* root;

/**
* \brief Fonction lance le programme
* \return void
*/

void lancement();
/**
* \brief Fonction qui créer une ligne avec un point origine et un avancement
* \param origine le point de départ
* \param val la valeur d'avancement du point
* \return le nouveau point
*/

POINT *pointfinligne(POINT* origine, int val); //Point de destination après création d'une ligne : nouvelle origine
/**
* \brief Fonction qui génère le graphique créer
* \param noeud le noeud contenant tout le programme qui va être traité
* \param fichier le fichier dans lequel tout va être exporté
* \param origine le point de départ du graphique
* \return le graphique
*/

void generersvg(NODE* noeud, FILE* fichier, POINT* origine);

	
	

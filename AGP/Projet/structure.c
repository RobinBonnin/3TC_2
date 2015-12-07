#include <stdio.h>
#include "structure.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define FORWARD 1
#define REPEAT 2
#define LEFT 3
#define RIGHT 4
#define PI 3.14159265359
int i=0;
int indent=0;

//-----------------------------------------------
void effacerNode(NODE* noeudsource){
	NODE* noeudeffacer=noeudsource;	
	if ( noeudsource != NULL )
   { //parcours postfixe
     if ( noeudsource->sousProgramme != NULL )
       effacerNode( noeudsource->sousProgramme );
     if ( noeudsource->instructionSuivant!= NULL )
       effacerNode( noeudsource->instructionSuivant );
     free( noeudsource );
     noeudsource = NULL;  
   }
}		

//-----------------------------------------------
NODE* newNode (int inst,int Val, NODE* sousProg,NODE* instSuivant){ //Création d'un nouveau noeud
	NODE* cursor;
	cursor=(NODE*)malloc(sizeof(NODE));
	if(cursor==NULL)
		exit(-1);
		else{
	cursor->instruction=inst;
	cursor->val=Val;
	cursor-> sousProgramme=sousProg;
	cursor->instructionSuivant=instSuivant;
	}
return cursor;
}
//-----------------------------------------------
NODE* addNode (NODE* noeudSource,NODE* programme){ // On ajoute un noeud à celui existant et on le poin par instructionSuivant
	if(programme==NULL){
	fprintf(stderr,"Err : instruction vide\n");
		exit(-1);
	}		
	else if (noeudSource->instructionSuivant!=NULL){
			noeudSource->instructionSuivant=addNode(noeudSource->instructionSuivant,programme);
			}
			else {
			noeudSource->instructionSuivant=programme;
	}
return(noeudSource);		
}		
//-----------------------------------------------
/*
 * \brief Programme imprime le programme entré en paramètre
 * \return void
 * \see printProgram
 */
void printProgram(NODE* programme){ //Afficher le programme
	int j=0;
	for(j = 0; j<indent; j++){
			printf("	");
		}
	if(i==0){
		printf("\n");
		i++;
	}
	if(programme==NULL){ 
		fprintf(stderr,"Err : Programme NULL\n");
		exit (0);
	}
	else{		
	switch(programme->instruction){
		case 1 :
		printf("FORWARD %d\n",programme->val);		
		break;
		case 2 :
		indent++;
		printf("REPEAT %d [\n",programme->val);
		printProgram(programme->sousProgramme);
		for(j = 0; j<indent-1; j++){
			printf("	");
		}
		printf("]\n");
		indent--;
		break;
		case 3 :
		printf("LEFT %d\n",programme->val);
		break;
		case 4 :
		printf("RIGHT %d\n",programme->val);		
		break;
		default :
		break;
	}
	}
	if(programme->instructionSuivant!=NULL){
		printProgram(programme->instructionSuivant);
	}
}
//-----------------------------------------------
POINT *creer_point(double x, double y, double direction){ //Création d'un point pour SVG
	POINT* point =malloc(3*sizeof(double));
	point->x=x;
	point->y=y;
	point->direction=direction;
	return point;
}
//-----------------------------------------------
void lancement(NODE* node){ //On met dans dessin.svg les commandes données par test.logo
	
	FILE* dessin= fopen("dessin.svg","w+");
	if(dessin == NULL){
		printf("Le fichier s'est mal ouvert\n");
	}
	
	POINT* origine = creer_point(150,150,0); // Origine au milieu du fichier
		
	fprintf(dessin,"<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?> \n <svg version=\"1.1\" width=\"1000\" height=\"1000\">\"?>\n"); // en tête du fichier SVG
	generersvg(node,dessin,origine);
	fprintf(dessin,"</svg>");
	effacerNode(node);
	free(origine);
	printf("\n");
}


//-----------------------------------------------
void generersvg(NODE* noeud, FILE* fichier, POINT* origine){
	
	
	if(fichier == NULL){
		printf("Le fichier s'est mal ouvert\n");
	}
	
	NODE* curseur = noeud;
	while(curseur != NULL){
	
		if (curseur->instruction==1){//Forward

			
		fprintf(fichier,"<line x1=\"%.3f\" y1=\"%.3f\"",origine->x,origine->y);
		origine->x = origine->x + curseur->val*cos(origine->direction);
		origine->y = origine->y + curseur->val*sin(origine->direction);
		fprintf(fichier," x2=\"%.3f\" y2=\"%.3f\" stroke=\"blue\" />\n",origine->x,origine->y);

		}
		else if (curseur->instruction==4){//right

			origine->direction += (curseur->val)*PI/180;
		}
		else if(curseur->instruction==3){ //Left
			origine->direction -= (curseur->val)*PI/180;
		}
		else if(curseur->instruction==2){ //Repeat
			int i;
			for(i=0; i< curseur->val; i++){
				generersvg(curseur->sousProgramme,fichier,origine);
			}
		}
		else{
			printf("Erreur d'instructions\n");
		}
	
		curseur=curseur->instructionSuivant;
	}
}
	
	

	



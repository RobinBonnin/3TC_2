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



void effacerNode(NODE* noeudsource){
	NODE* noeudeffacer=noeudsource;
	NODE* noeudsuivant;

	if(noeudeffacer->sousProgramme!=NULL){
		//free(noeudsource);
		//printf("Plouf\n");
	}

	if(noeudeffacer!=NULL){
		noeudsuivant=noeudeffacer->instructionSuivant;
		free(noeudsource);
		effacerNode(noeudsuivant);
	}
}		


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

void printProgram(NODE* programme){ //Afficher le programme
	if(programme==NULL){ 
		fprintf(stderr,"Err : Programme NULL\n");
		exit (0);
	}
	else{		
	switch(programme->instruction){
		case 1 :
		printf("\n");
		printf("FORWARD %d",programme->val);		
		break;
		case 2 :
		printf("\nREPEAT %d \n	[",programme->val);
		switch(programme->sousProgramme->instruction){
			case 1:
			printf("FORWARD %d" ,programme->sousProgramme->val);
			if(programme->sousProgramme->instructionSuivant!=NULL)
			printProgram(programme->sousProgramme->instructionSuivant);			
				printf( "]");
			break;
			case 2 :
			printf("REPEAT %d[\n		",programme->sousProgramme->val);
			printProgram(programme->sousProgramme->sousProgramme); 
			if(programme->sousProgramme->instructionSuivant!=NULL)
			printProgram(programme->sousProgramme->instructionSuivant);
			printf("]]");
			break;
			case 3 : 
			printf("LEFT %d",programme->sousProgramme->val);
			if(programme->sousProgramme->instructionSuivant!=NULL) 
			printProgram(programme->sousProgramme->instructionSuivant);
				printf( "]");
			break;
			case 4 :
			printf("RIGHT %d",programme->sousProgramme->val);
			if(programme->sousProgramme->instructionSuivant!=NULL)
			printProgram(programme->sousProgramme->instructionSuivant);
			printf("]");
			break;
		}
		printf("\n");			
		break;
		case 3 :
		printf("\n");
		printf("LEFT %d",programme->val);
		break;
		case 4 :
		printf("\n");
		printf("RIGHT %d",programme->val);		
		break;
		default :
		break;
	}
	}
	if(programme->instructionSuivant!=NULL){
		printProgram(programme->instructionSuivant);
	}
	else 
	printf("\n");
	//effacerNode(programme);
}

POINT *creer_point(double x, double y, double direction){ //Création d'un point pour SVG
	POINT* point =malloc(3*sizeof(double));
	point->x=x;
	point->y=y;
	point->direction=direction;
	return point;
}

void lancement(NODE* node){ //On met dans dessin.svg les commandes données par test.logo
	
	FILE* dessin= fopen("dessin.svg","w+");
	if(dessin == NULL){
		printf("Le fichier s'est mal ouvert\n");
	}
	
	POINT* origine = creer_point(150,150,0); // Origine au milieu du fichier
		
	fprintf(dessin,"<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?> \n <svg version=\"1.1\" width=\"300\" height=\"200\">\"?>\n"); // en tête du fichier SVG
	generersvg(node,dessin,origine);
	fprintf(dessin,"</svg>");
	effacerNode(node);
	free(origine);
}



void generersvg(NODE* noeud, FILE* fichier, POINT* origine){
	
	//printf("on est dans generersvg\n");
	
	if(fichier == NULL){
		//printf("Le fichier s'est mal ouvert\n");
	}
	
	NODE* curseur = noeud;
	while(curseur != NULL){
	
		if (curseur->instruction==1){//Forward
		//printf("forward\n");
			
		fprintf(fichier,"<line x1=\"%.3f\" y1=\"%.3f\"",origine->x,origine->y);
		origine->x = origine->x + curseur->val*cos(origine->direction);
		origine->y = origine->y + curseur->val*sin(origine->direction);
		fprintf(fichier," x2=\"%.3f\" y2=\"%.3f\" stroke=\"blue\" />\n",origine->x,origine->y);

		}
		else if (curseur->instruction==4){//right
			//printf("right\n");
			origine->direction += (curseur->val)*PI/180;
		}
		else if(curseur->instruction==3){ //Left
			//printf("left\n");
			origine->direction -= (curseur->val)*PI/180;
			//printf("x1=%.3f y1=%.3f \n",origine->x,origine->y);
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
	
	

	



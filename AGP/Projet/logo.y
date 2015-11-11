%{
#include <stdio.h>
#include "structure.h"
#include "math.h"

  void yyerror (){
    fprintf(stderr,"erreur détéctée dans le programme LOGO\n");
  }

int yywrap(){
    return 1;
}


%} //Règles

%token VALUE
%token FORWARD
%token REPEAT
%token LEFT
%token RIGHT

  //type de yyval

%union{
	NODE* NODE_TYPE;
 	int val;
};

//types

%type <val> VALUE
%type <NODE_TYPE> INST PROG FILE
%type <NODE_TYPE> FORWARD REPEAT LEFT RIGHT

%%

FILE : PROG
{ 
  root=$1;
}

//programme

PROG : INST 
{ 
  $$=$1;
}
|PROG INST 
{
  addNode($1,$2);
  $$=$1;
}

//Instructions

INST : FORWARD VALUE {
         $$=newNode(1,$2,NULL,NULL);
       }

|LEFT VALUE {
  $$=newNode(3,$2,NULL,NULL);
}

  |RIGHT VALUE {
  $$=newNode(4,$2,NULL,NULL);
  }

  |REPEAT VALUE '['PROG']'
  {
    $$=newNode(2,$2,$4,NULL);
}

%%
main(){
		
	    yyparse();
        printProgram(root);
        lancement(root);
        return 0;
}

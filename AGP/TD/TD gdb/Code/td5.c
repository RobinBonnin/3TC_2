#include <stdio.h>
#include <stdlib.h>
#include "td5_type.h"
#include "td5.h"


int arbreEquilibre (ARBRE arbre)
{
  if (arbre==NULL) return(TRUE);
  else
    {
      if (abs(hauteurArbre(arbre->filsGauche)-
	      hauteurArbre(arbre->filsDroit))<=1)
	{
	  return(arbreEquilibre(arbre->filsGauche) &&
		 arbreEquilibre(arbre->filsDroit));
	}
      else
	return(FALSE);
    }
}
  


 
ARBRE nouvelArbre(int val, ARBRE fg, ARBRE fd)
{
  ARBRE temp;

  temp= (ARBRE)malloc(sizeof(NOEUD));
  temp->val=val;
  temp->filsGauche=fg;
  temp->filsDroit=fd;
  return(temp);
}

int hauteurArbre(ARBRE arbre)
{int fg,fd,res;
  if (arbre==NULL) 
    {
      return(-1);
    }
  else
    {
      fg=hauteurArbre(arbre->filsGauche)+1;
      fd=hauteurArbre(arbre->filsDroit)+1;
      res= (fg > fd) ? fg : fd;
      return(res);
    }
}

void afficherArbre(ARBRE arbre, int decalage)
{int i;
 if (arbre!=NULL)
   {
     for (i=0;i<decalage;i++)
       fprintf(stdout," ");
     fprintf(stdout,"  +-");
     fprintf(stdout,"%4d\n",arbre->val);
     afficherArbre(arbre->filsDroit,decalage+4);
     afficherArbre(arbre->filsGauche,decalage+4);
   }
}


int main()
{
  
  
  
  ARBRE arbre, temp1,temp2,temp;
  
  temp1=nouvelArbre(10,NULL,NULL);
  temp2=nouvelArbre(20,NULL,NULL);
  arbre=nouvelArbre(30,temp1,temp2);
  afficherArbre(arbre,0);
  fprintf(stdout,"hauteur(arbre)=%d\n",hauteurArbre(arbre));

  temp1=nouvelArbre(40,NULL,NULL);
  temp2=nouvelArbre(50,NULL,NULL);
  temp1=nouvelArbre(60,temp1,temp2);
  arbre=nouvelArbre(70,arbre,temp1);
  arbre=nouvelArbre(80,arbre,temp2);

  afficherArbre(arbre,0);
  fprintf(stdout,"hauteur(arbre)=%d\n",hauteurArbre(arbre));
  
  

  temp=NULL;
  afficherArbre(temp,0);
  if (arbreEquilibre(temp)) fprintf(stdout,"arbre Equilibre\n");
  else  fprintf(stdout,"arbre NON Equilibre\n");
  temp1=nouvelArbre(10,NULL,NULL);
  temp2=nouvelArbre(20,NULL,NULL);
  arbre=nouvelArbre(30,temp1,temp2);
  afficherArbre(arbre,0);
  if (arbreEquilibre(arbre)) fprintf(stdout,"arbre Equilibre\n");
  else  fprintf(stdout,"arbre NON Equilibre\n");

  temp1=nouvelArbre(40,NULL,NULL);
  temp2=nouvelArbre(50,NULL,NULL);
  temp1=nouvelArbre(60,temp1,temp2);
  arbre=nouvelArbre(70,arbre,temp1);
  arbre=nouvelArbre(80,arbre,temp2);

  afficherArbre(arbre,0);
  if (arbreEquilibre(arbre)) fprintf(stdout,"arbre Equilibre\n");
  else  fprintf(stdout,"arbre NON Equilibre\n");
  
  free(arbre);
  free(temp1);
  free(temp2);
  free(temp); 
  return(0);
}

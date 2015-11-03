#include "ioHelpers.h"

//-------------------------------
void PrintTable(int t[],int l)
{
  int i;
  for(i=0;i<l;i++) 
    printf("%d\n",t[i]);
}


//--------------------------------
void ReadData(char *NomFic, int t[],int l)
{
  int i;
  FILE *f;

  f=fopen(NomFic, "r");
  if (f==NULL) 
    {
      printf("Erreur d'ouverture %s\n", NomFic);
      exit(1) ;
    }

  for(i=0;i<l;i++) fscanf(f,"%d",&t[i]);
  fclose(f);
}

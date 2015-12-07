#include <stdio.h>
#include <stdlib.h>



int divise( int  a, int b )
{int *temp;

  temp=(int *)(a-b);
  *temp=0;

  return *temp;
}

void affiche( int  a, int b )
{
  fprintf(stdout,"a=%d, b=%d\n",a,b);
}

int main (  )
{ int i,a,b;
  
  a=0;
  b=0;
  for (i=0;i<5;i++)
    {
      a++;
      b++;
      affiche(a,b);
    }

  divise(a,b);
 
  return 0;
}

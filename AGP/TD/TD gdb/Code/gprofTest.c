#include <stdio.h>
#include <stdlib.h>

//#define DEBUG // pour debugger


int pgcd (int a, int b)
{
  int res;

#ifdef DEBUG
  fprintf(stdout,"Entree dans pgcd: a=%d, b=%d\n",a,b);
#endif
  if (a>b)
    {
      if (a%b==0) 
        res=b;
      else
        res=pgcd(b,a%b);
    }
    else
      {
        if (b%a==0) 
          res=a;
        else
          res=pgcd(a,b%a);
      }
  return(res);
}

  

int carre (int a)
{
  int temp,res;


  if (a==1)
    res=1;
  else
    {
      temp=carre(a-1);
      res=temp+2*a-1;
    }

  
  return(res);
}


  

int cnp (int n, int k)
{
  int temp1,temp2,res;

#ifdef DEBUG
  fprintf(stdout,"Appel CNP n=%d k=%d \n",n,k);
#endif 
  if ((k==n)||(k==0))
    res=1;
  else
    {
      temp1=cnp(n-1,k-1);
      temp2=cnp(n-1,k);
      res=temp1+temp2;
    }
   
#ifdef DEBUG
  fprintf(stdout,"Appel CNP n=%d k=%d vaut %d\n",n,k,res);
#endif  
  return(res);
}

        
int main(int  argc, char *argv[])
{
  int i,nbIter,res;
  
  nbIter = 30;
  for (i=1;i<nbIter; i++)
    {
      pgcd(i,7);
      carre(i);
      res=cnp(i,i/3);
      fprintf(stdout,"iteration %d: res=%d \n",i,res);
    }

  return(0);
}

  

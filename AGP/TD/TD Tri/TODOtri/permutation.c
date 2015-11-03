#include "permutation.h"

void permutation(int d[],int a,int b)
{
  int i;
  i=d[a];
  d[a]=d[b];
  d[b]=i;
}

/* 
gentil.c (source Michel Simatic)
*/ 

#include "constantes.h" 

char t[LIGNES][COLS]; 

main() { 
int i,j,k; 
for (i=0 ;i<2 ;i++) { 
  for (j=0 ;j<LIGNES ;j++) {
    for (k=0 ;k<COLS ;k++) {
      t[j][k] = 1;
    }
  }
}
return 0;
} 

#include "triFusion.h"
#include <stdio.h>

void fusion(int T[], int N, int S[], int M, int TS[]){
	int t=0, s=0, ts=0;
	while(t<N && s<M){
		if(T[t]< S[s] ) {
			TS[ts]= T[t];
			t++;
		}
		else {
			TS[ts]=S[s];
			s++;
		}
		ts++;
	}
	while(s<M){
		TS[ts]=S[s];
		s++;
		ts++;
	}
	while(t<N) {
		TS[ts]=T[t];
		t++;
		ts++;
	}
				
}


void triFusion(int d[], int N){
	int taille2=0, taille1=0;
	int i=0;
	int k=0;
	if(N>1){
		taille1=N/2;
		taille2=N/2+N%2;
		int T[taille1];
		int S[taille2];
		for(i=0; i<taille1;i++){
			T[i]=d[i];
		}
		for(k=taille1; k<N;k++){
			S[k-taille1]=d[k];
		}
		triFusion(T,taille1);
		triFusion(S,taille2);
		fusion(T,taille1,S,taille2,d);
	}
}

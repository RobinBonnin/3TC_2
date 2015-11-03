#include<stdio.h>
#include<stdlib.h>

#define N 64

int lirefichier ( FILE *file, char tabchar[N] ) {
	char c;
	int i=0;
	c=fgetc(file);
	
	while (c!= '\n' && c != EOF) {
		if(i>N-1) {
			break;
		}
			
		tabchar[i]=c;
		i++;
		c=fgetc(file);
		
	}
	if(c==EOF){
		return(1);
	}
	tabchar[i]=c;
	
	return(0);
}

int hextoascii ( char c ) {
	int i=0;
	if(c > 47 && c <= 57) {
		i = c - 48;
	}
	else if(c > 64 && c <= 70) {
		i = c - 55;
	}
	
	return i;
}

int verif ( char tabchar[N]) {
	
	if (tabchar[0]-48 > 5 ) {
		printf(": %d\n", tabchar[0]);
		return -1;
	}
	
	int i = 1;
	while(tabchar[i] != '\n' && tabchar[i] != EOF) {
		i++;
	}
	int checksum = hextoascii(tabchar[i-1]); 
	if(checksum%8 != (i-2)%8) {
		//printf("%c // %d // %d\n", tabchar[i-1], checksum, i-2);
		return -1;
	} else if ( i == 2) {
		return -2;
	} else {
		//printf("%c\n",  tabchar[0]);
		return tabchar[0]-48;
	}
}

int ecrirefichier(FILE* file, char tabchar[N], int o, int octets[6]) {
	int j=0;
	int i=2;
	while(tabchar[i] != '\n'){
		fputc(tabchar[i-1],file);
		octets[o]++;
		i++;
		if((i-2)%7==0){
			fputc('7',file);
			fputc('\n',file);
		}
	}
	if((i-2)%7 != 0){
		for(j = (i-2)%7;j < 7;j++) {
			fputc('?', file);
		}
		fputc((i-2)%7+48, file);
		fputc('\n', file);
	}
	
	return(0);
}

int main() {
	int numfich=0;
	char tabchar[N];
	int octets[6] = {0, 0, 0, 0, 0, 0};
	int acc=0;
	int rej=0;
	FILE *f1,*f2,*f3,*f4,*f5,*f0,*data;
	data = fopen("data.sujet", "r+");
	f0 = fopen("f0","w+");
	f1 = fopen("f1","w+");
	f2 = fopen("f2","w+");
	f3 = fopen("f3","w+");
	f4 = fopen("f4","w+");
	f5 = fopen("f5","w+");
	while(lirefichier (data, tabchar) == 0){
		int i = 2;
		numfich=verif(tabchar);	
		switch (numfich) {
			case 1 :
			acc++;
			ecrirefichier(f1,tabchar, 1, octets);
			break;
			case 2 :
			acc++;
			ecrirefichier(f2,tabchar, 2, octets);
			break;
			case 3 :
			acc++;
			ecrirefichier(f3,tabchar, 3, octets);
			break;
			case 4 :
			acc++;
			ecrirefichier(f4,tabchar, 4, octets);
			break;
			case 5 :
			acc++;
			ecrirefichier(f5,tabchar, 5, octets);
			break;
			case -1 :
			rej++; 
			while(tabchar[i] != '\n'){
				fputc(tabchar[i-1],f0);
				octets[0]++;
				i++;
			}
			fputc('\n', f0);
			break;
			case -2 :
			break;

		}
	}
	printf("Ratio rejetées/total = %d/%d\n", rej, rej+acc);
	
	int n;
	for(n = 0; n < 6; n++) {
		printf("Fichier %d : %d octets\n", n, octets[n]);
	}
	
	fclose(data);
	fclose(f0);
	fclose(f1);
	fclose(f2);
	fclose(f3);
	fclose(f4);
	fclose(f5);
	return(0);
}

		
	
	

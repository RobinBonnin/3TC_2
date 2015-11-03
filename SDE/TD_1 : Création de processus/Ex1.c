#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	int pid1=0;
	int pid2=0;
	int pid11=0;
	int pid12=0;
		
	pid1=fork();
	switch (pid1) {
		case 0 :
			printf("Je suis le fils 1 (pid : %d) et mon père est %d\n", getpid(), getppid());
			pid11=fork();
			if(pid11==0){
				printf("Je suis le fils 1.1 (pid : %d) et mon père est %d\n", getpid(), getppid());
			}
			if (pid11 >0) {
				pid12=fork();
				if(pid12==0)
				printf("Je suis le fils 1.2 (pid: %d) et mon père est %d\n", getpid(), getppid() );
				wait(5);
			}
			wait(10);
			break;
		case -1 :
			return(-1);
			break;
		default : 
			printf("Je suis le père pid : %d\n", getpid());
			pid2=fork();
			if(pid2==0){
				printf("Je suis le fils 2 (pid : %d) et mon père est %d\n", getpid(), getppid());
			}
			wait(5);
			break;
		}
	return(0);
}
	
		
	

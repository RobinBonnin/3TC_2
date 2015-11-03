#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <wait.h>

int main () {
	int pause=0;
	int pid=0;
	int code=0;
	pid = fork();
	if(pid == 0) {
		printf("(pid: %d - %d) Entrez un code\n", getpid(), getppid());
		scanf("%d", &code);
		exit(code);
	}
	else if (pid<0) {
		printf("Erreur dans la création du processus fils\n");
	}
	else {
		wait(&pause);
		printf("Le code du fils est %d\n", WEXITSTATUS (pause));
	}
	return(0);
}
		

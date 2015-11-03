#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <wait.h>

int main () {
	int pid=0;
	int status;

	pid = fork();
	if(pid == 0) {
		sleep(10);
	}
	else if (pid ==-1) {
		printf("Erreur de création du fils\n");
		return (-1);
	}
	else {
		wait(&status);
		kill(pid, SIGKILL); 
	}
	return 0;
}

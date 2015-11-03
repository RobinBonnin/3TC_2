#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <wait.h>

int pid = 0;
int test = 0;
int timer = 0;

void demarrage_stop(){
	int status;
	
	if(getpid() == test) {
		waitpid(pid, &status, WNOHANG | WUNTRACED);
		if(WIFSTOPPED(status) != 0) {
			printf("Reprise du chrono\n");
			kill(pid, SIGCONT);
		}else {
			printf("Arrêt du chrono\n");
			kill(pid, SIGSTOP);
		}
	}
}

void raz() {
	int status;
	
	if(getpid() == test) {
		kill(pid, SIGUSR1);
	}	
}

void rz() {
	timer = 0;
	printf("Remise à zéro du compteur.\n");
}

int main() {
	
	pid = fork();
	
	if(pid == 0) {
		signal(SIGUSR1, rz);
		while(1) {
			sleep(1);
			timer++;
			printf("Temps : %d\n", timer);
		}
	}	else if (pid ==-1) {
		printf("Erreur de création du fils\n");
		return (-1);
	} else {
		test = getpid();
		signal(SIGUSR1, demarrage_stop);
		signal(SIGUSR2, raz);
		
		while(1) {
		}
	}
}

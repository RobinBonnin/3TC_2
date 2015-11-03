#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <wait.h>

void rien() {
	printf("Pause\n");
}

int main () {

	int timer=0;
	printf("Entrer un temps de pause\n");
	scanf("%d", &timer);
	alarm(timer);
	signal(SIGALRM, rien);
	pause();
	
	return 0;
}

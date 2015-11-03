#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <wait.h>

int main() {
	int pid=0;
	pid=fork();
	if (pid==0) {
		exit(0);
	}
	else {
		sleep(5);
	}
	return 0;
}

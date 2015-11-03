#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main () {
	int id;
	int pid;
	pid = fork();
	struct msgbuf {
		long mtype;
		int mtext;
	} message;
	if(pid == 0) {
		key_t cle = 100;		
		id=msgget(cle,0666|IPC_CREAT);
		while(1) {
			sleep(1);
			printf("Entrez un nombre\n");
			scanf("%d",&message.mtext);
			
			message.mtype = 1;
			msgsnd(id,&message,sizeof(message.mtext),0);
		}
	}
	else {
		key_t cle = 100;
		id = msgget(cle,0666);
		while(1) {
			msgrcv(id,&message,100,1,0);
			printf("%d\n", message.mtext);
			if(message.mtext < -1 ) {
				kill(pid,SIGKILL);
				exit(-1);
			}
		}
	}
	return 0;
}

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/sem.h>

int ouvrirsem(key_t cle);
int supprimersem(int idsem);
void initsem(int idsem, int val);
void down(int idsem);
void up(int idsem);
void couperCheveux();
void obtenirCoupe();

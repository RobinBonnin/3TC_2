CFLAGS = -g -Wall -DDEBUG
LDLAGS = -g -Wall -DDEBUG

all: coordinateur generateur_traffic

generateur_traffic.o: generateur_traffic.c 
	gcc ${CFLAGS} -c generateur_traffic.c  -o generateur_traffic.o

coordinateur.o:	coordinateur.c
	gcc ${CFLAGS} -c coordinateur.c -o coordinateur.o

coordinateur: coordinateur.o
	gcc ${LDFLAGS} coordinateur.o -o Coordinateur

generateur_traffic: generateur_traffic.o
	gcc ${LDFLAGS} generateur_traffic.o -o Generateur_traffic

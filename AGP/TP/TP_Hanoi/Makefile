CFLAGS = -g -Wall -DDEBUG
LDLAGS = -g -Wall -DDEBUG

all: main

hanoi.o: hanoi.c 
	gcc ${CFLAGS} -c hanoi.c  -o hanoi.o


main.o:	main.c
	gcc ${CFLAGS} -c main.c -o main.o

pile.o: pile.c
	gcc ${LDFLAGS} -c pile.c -o pile.o

main: main.o hanoi.o pile.o
	gcc ${LDFLAGS} main.o pile.o hanoi.o -o main

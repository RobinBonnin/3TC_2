#########################################################
# Makefile pour les programme du TD3 AGP
# Tanguy Risset, 2005
#########################################################
CC            =gcc 
LD	      =gcc
#cible principales: on construit les executables et les test
#CFLAGS	+=  -c -O3  -g -I./
CFLAGS	+=  -Wall  -g -I./  
EXE=valgrindEx gprofTest bug td5 gentil mechant testGDB
OBJ= 
all: ${EXE}

run: ${EXE}
	td5
%.o: %.c 
	${CC} ${CFLAGS} $< -o $@

bug:	bug.c

valgrindEx: valgrindEx.c

td5: td5.c

gprofTest: gprofTest.c
	${CC} ${CFLAGS} -p   gprofTest.c  -o $@

tar: clean
	cd ..; tar cvf TDGDB.tar  --exclude Code/td5Corr.c  Code/*.c Code/*.h Code/Makefile; gzip TDGDB.tar 

clean:
	-rm -f *~ *.out $(EXE) *.o valgrindEx mechant gentil bug td5Corr gprofTest



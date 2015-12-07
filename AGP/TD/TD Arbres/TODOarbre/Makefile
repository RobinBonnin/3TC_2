#########################################################
# Makefile pour les programme du TD5 AGP: arbres
# Tristan Roussillon, 2013
#########################################################

# Variables pour le compilateur et l'editeur de lien 
CC            =gcc 
CFLAGS        += -Wall -g

# Variables
EXE=test
# fichiers sources
SRC=TODOarbre.c arbre.c test.c
# fichiers objets
OBJ=$(SRC:.c=.o)

#cible principale 
all: $(OBJ) $(EXE)

#edition de liens
$(EXE): $(OBJ) 
	$(CC) $(OBJ) -o $@

#regle generique pour compiler sans edition de liens
%.o: %.c 
	$(CC) -c $(CFLAGS)  $<  -o $@

#lancement des tests
run:
	valgrind --leak-check=full ./$(EXE)


export: clean
	mkdir ../TODOarbre
	cp ./* ../TODOarbre
	rm ../TODOarbre/TODOarbre.c
	touch ../TODOarbre/TODOarbre.c
	tar cvf ../TODOarbre.tar ../TODOarbre
	rm -R ../TODOarbre

#documentation
doc:	doxyfile 
	doxygen doxyfile

clean:
	rm -rf *~ *.out *.o html *.svg
	rm -f $(EXE)


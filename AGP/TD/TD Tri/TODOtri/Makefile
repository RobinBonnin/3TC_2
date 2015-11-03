#########################################################
# Makefile pour le programme du TD2 AGP
# Tristan Roussillon, 2013
#########################################################

# Variables pour le compilateur et l'editeur de lien 
CC            =gcc 
CFLAGS        += -Wall -g

#ensemble des executables
EXE=test demo benchmark
#ensemble de fhichers objets
OBJ=ioHelpers.o permutation.o triBulle.o triFusion.o triRapide.o

#cible principale 
all: $(OBJ) $(EXE)

#regle generique pour fabriquer les exécutables
%: %.c $(OBJ) 
	$(CC) $(CFLAGS) $< $(OBJ) -o $@

#regle generique pour fabriquer les fichiers objets
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

export: clean
	mkdir ../TODOtri
	cp ./* ../TODOtri
	rm ../TODOtri/triFusion.c
	touch ../TODOtri/triFusion.c
	tar cvf ../TODOtri.tar ../TODOtri
	rm -R ../TODOtri

doc:	doxyfile
	doxygen doxyfile

clean:
	rm -rf *~ *.out *.o html *.svg
	rm -f $(EXE)


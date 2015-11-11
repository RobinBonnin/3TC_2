

all: logo

maison: 
	./logo <test.logo_maison
	eog dessin.svg
test: 
	./logo <test.logo
	eog dessin.svg
cercle:
	./logo<test.logo_cercle
	eog dessin.svg
logo: logo.tab.c lex.yy.c structure.c 
	gcc logo.tab.c lex.yy.c structure.c -lm -o logo

logo.tab.c : logo.y
	bison -d logo.y

lex.yy.c : flogo.l
	flex flogo.l 

clean :
	@rm -rf *.o rm -rf *.bak rm -rf *.gch *~ rm main rm logo rm -rf lex.yy.c rm -rf *.tab.c rm -rf *.tab.h rm -rf *.svg

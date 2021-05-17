OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Problema.o Cjt_problemes.o Cjt_sessions.o Sessio.o Curs.o Cjt_cursos.o Usuari.o Cjt_usuaris.o
	g++ -o program.exe program.o Problema.o Cjt_problemes.o Usuari.o Cjt_usuaris.o Cjt_sessions.o Sessio.o Curs.o Cjt_cursos.o

program.o: program.cc
	g++ -c program.cc $(OPCIONS)

Cjt_cursos.o: Cjt_cursos.cc
	g++ -c Cjt_cursos.cc $(OPCIONS)

Curs.o: Curs.cc
	g++ -c Curs.cc $(OPCIONS)

Cjt_sessions.o: Cjt_sessions.cc
	g++ -c Cjt_sessions.cc $(OPCIONS)

Sessio.o: Sessio.cc
	g++ -c Sessio.cc $(OPCIONS)

Cjt_usuaris.o: Cjt_usuaris.cc
	g++ -c Cjt_usuaris.cc $(OPCIONS)

Usuari.o: Usuari.cc
	g++ -c Usuari.cc $(OPCIONS)

Cjt_problemes.o: Cjt_problemes.cc
	g++ -c Cjt_problemes.cc $(OPCIONS)

Problema.o: Problema.cc
	g++ -c Problema.cc $(OPCIONS)

clear:
	rm *.exe
	rm *.o
	rm *.tar
practica.tar:
	tar -cvf practica.tar *.cc Makefile Curs.hh Cjt_cursos.hh Problema.hh Cjt_problemes.hh Sessio.hh Cjt_sessions.hh Usuari.hh Cjt_usuaris.hh ExcepcioEvaluator.hh


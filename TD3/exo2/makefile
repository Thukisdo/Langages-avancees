cc=g++
CFLAGS=-g -Wall -Werror -Wextra -pedantic

all: Forme.o Cercle.o Rectangle.o Groupe.o Point.o
	$(cc) $(CFLAGS) main.cpp Forme.o Cercle.o Rectangle.o Groupe.o Point.o -o main.out

Forme.o: Forme.cpp Forme.hpp 
	$(cc) $(CFLAGS) -c Forme.cpp -o $@

Rectangle.o: Rectangle.cpp Rectangle.hpp
	$(cc) $(CFLAGS) -c Rectangle.cpp -o $@

Cercle.o: Cercle.cpp Cercle.hpp
	$(cc) $(CFLAGS) -c Cercle.cpp -o $@

Groupe.o: Groupe.cpp Groupe.hpp
	$(cc) $(CFLAGS) -c Groupe.cpp -o $@

Point.o: Point.cpp Point.hpp
	$(cc) $(CFLAGS) -c Point.cpp -o $@

clear:
	rm *.o *.out
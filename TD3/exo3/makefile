cc=g++
CFLAGS=-g -Wall -Werror -Wextra -pedantic


all: CPile.o CList.o main.cpp CFile.o
	$(cc) $(CFLAGS)	main.cpp CPile.o CList.o CFile.o -o main.out

CPile.o: CPile.cpp CPile.hpp
	$(cc) $(CFLAGS)	-c CPile.cpp -o $@


CList.o: CList.cpp CList.hpp
	$(cc) $(CFLAGS)	-c CList.cpp -o $@

CFile.o: CFile.cpp CFile.hpp
	$(cc) $(CFLAGS)	-c CFile.cpp -o $@

clear:
	rm *.o *.out
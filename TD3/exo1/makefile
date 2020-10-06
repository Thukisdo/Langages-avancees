cc=g++
CFLAGS = -g -Og -Wall -Werror -Wextra -pedantic


all : Point.o PointColor.o
	$(cc) $(CFLAGS) main.cpp Point.o PointColor.o -o main.out

Point.o : Point.cpp Point.hpp
	$(cc) $(CFLAGS) -c Point.cpp -o Point.o

PointColor.o : PointColor.cpp PointColor.hpp
	$(cc) $(CFLAGS) -c PointColor.cpp -o PointColor.o

clear:
	rm *.o *.out
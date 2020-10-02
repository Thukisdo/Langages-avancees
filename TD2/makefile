cc=g++
CFLAGS=-g 

all : exo1.out exo2.out exo3.out


exo1.out : exo1.cpp CString.cpp CString.hpp
	$(cc) $(CFLAGS)  -o $@ CString.cpp $<

exo2.out : exo2.cpp
	$(cc) $(CFLAGS)  -o $@ $<

exo3.out : exo3.cpp CString.cpp CString.hpp
	$(cc) $(CFLAGS)  -o $@ CString.cpp $<

clear :
	rm *.out
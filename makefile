cc=g++
CFLAGS=-g 

all : exo1.out exo2.out exo3.out exo4.out exo5.out exo6.out exo7.out


exo1.out : exo1.cpp
	$(cc) $(CFLAGS)  -o $@ $<

exo2.out : exo2.cpp
	$(cc) $(CFLAGS)  -o $@ $<
exo3.out : exo3.cpp

	$(cc) $(CFLAGS)  -o $@ $<
exo4.out : exo4.cpp
	$(cc) $(CFLAGS)  -o $@ $<

exo5.out : exo5.cpp
	$(cc) $(CFLAGS)  -o $@ $<

exo6.out : exo6.cpp
	$(cc) $(CFLAGS)  -o $@ $<

exo7.out : exo7.cpp
	$(cc) $(CFLAGS)  -o $@ $<

clear :
	rm *.out
CFLAGS= -Wall -Werror

all: exemplo1

exemplo1: exemplo1.o vetor.o
	gcc exemplo1.o vetor.o -o exemplo1

vetor.o: vetor.c vetor.h
	gcc $(CFLAGS) -c vetor.c

exemplo1.o: exemplo1.c vetor.h
	gcc $(CFLAGS) -c exemplo1.c
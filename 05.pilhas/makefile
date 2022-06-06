CFLAGS= -Wall -Werror

all: exemplo1

exemplo1: exemplo1.c pilha.o
	gcc $^ -o $@

#regra genérica
%.o: %.c %.h
	gcc $(CFLAGS) -c $<
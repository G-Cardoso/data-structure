CFLAGS= -Wall -Werror

all: exemplo2

exemplo1: exemplo1.c lista_circular.o
	gcc $^ -o $@

exemplo2: exemplo2.c lista_circular.o
	gcc $^ -o $@

valgrind: all
	valgrind --leak-check=yes ./exemplo1.c

#regra genérica
%.o: %.c %.h
	gcc $(CFLAGS) -c $<
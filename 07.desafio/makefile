CFLAGS= -Wall -Werror

all: exemplo1

exemplo1: exemplo1.c fila.o lista_circular.o
	gcc $^ -o $@

#regra genérica
%.o: %.c %.h
	gcc $(CFLAGS) -c $<
CFLAGS= -Wall -Werror

all: main

main: main.c fila.o lista_circular.o
	gcc $^ -o $@

#regra genérica
%.o: %.c %.h
	gcc $(CFLAGS) -c $<
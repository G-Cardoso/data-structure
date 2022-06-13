CFLAGS= -Wall -Werror
LIB_FILAS= ../../04.filas

all: distancias

distancias: distancias.c $(LIB_FILAS)/fila.o $(LIB_FILAS)/lista_circular.o
	gcc $^ -o $@

#regra genérica
%.o: %.c %.h
	gcc $(CFLAGS) -c $< $@
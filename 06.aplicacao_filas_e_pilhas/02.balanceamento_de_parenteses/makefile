CFLAGS= -Wall -Werror
LIB_PILHAS= ../../05.pilhas

all: parenteses

parenteses: parenteses.c $(LIB_PILHAS)/pilha.o
	gcc $^ -o $@

#regra genérica
%.o: %.c %.h
	gcc $(CFLAGS) -c $< $@
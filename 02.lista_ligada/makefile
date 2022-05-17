CFLAGS= -Wall -Werror

all: exemplo1

exemplo1: exemplo1.c lista_ligada.o
	gcc $^ -o $@

#Regra Genérica
%.o: %.c %.h
		gcc $(CFLAGS) -c $<
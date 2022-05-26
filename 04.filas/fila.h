#ifndef FILA_H
#define FILA_H

#include "lista_circular.h"

//dados
typedef struct {
    int tam;
    No *L;
} Fila;

//Funções
Fila* fila_criar();
void fila_destruir(Fila **F);

//Adicionar void
void fila_adicionar(Fila **F, int x);

//Acessar
int fila_topo(Fila *F);

//Remover
void fila_remover(Fila **F);

//Extra
int fila_tamanho(Fila *F);

#endif
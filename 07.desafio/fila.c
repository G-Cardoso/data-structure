#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

Fila* fila_criar(){
    Fila *p = (Fila*) malloc(sizeof(Fila));
    if(p==NULL){
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    p->tam = 0;
    p->L = criar_lista();
    return p;
}

void fila_destruir(Fila **p){
    destruir_lista(&(*p)->L);
    free(*p);
    *p = NULL;
}

void fila_adicionar(Fila **p, int i, int j){
    adicionar_final(&((*p)->L),i,j);
    (*p)->tam++;
}

void fila_topo(Fila *p, int* i, int* j){
    return acessar_primeiro(p->L, i, j);
}

void fila_remover(Fila **p){
    remover_inicio(&((*p)->L));
    (*p)->tam--;
}

int fila_tamanho(Fila *p){
    return p->tam;
}
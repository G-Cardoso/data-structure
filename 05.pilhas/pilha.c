#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>


Pilha* pilha_criar(){
    Pilha *P = (Pilha*) malloc(sizeof(Pilha));
    if(P==NULL){
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    P->dados = malloc(MAX * sizeof(int));
    if(P->dados==NULL){
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    P->topo = 0;
    P->N = MAX;
    return P;
}

void pilha_destruir(Pilha **p){
    free((*p)->dados);
    free(*p);
    *p = NULL;
}

void pilha_adicionar(Pilha **p, int x){
    (*p)->dados[(*p)->topo] = x;
    (*p)->topo++;
    //Verificar se não chegou no tamanho de N;
}

int pilha_topo(Pilha *p){
    return (p->topo)?p->dados[p->topo-1]:-1;
}

void pilha_remover(Pilha **p){
    if((*p)->topo==0) return;
    (*p)->topo--;
}

int pilha_tamanho(Pilha *p){
    return p->topo;
}
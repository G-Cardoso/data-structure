#include "vetor.h"
#include <stdio.h>
#include <stdlib.h>

vetor* criar_vetor(int tam){
    vetor *v;
    v = (vetor*) malloc(sizeof(vetor));
    if(v == NULL){
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    v->dados = (int*) malloc(tam * sizeof(int));
    if(v->dados == NULL){
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    v->n=0;
    return v;
}

void destruir_vetor(vetor *v){
    free(v->dados);
    free(v);
}

void adicionar_elemento(vetor *v, int x){
    v->dados[v->n] = x;
    v->n++;
}

int busca(vetor *v, int x){
    int i;
    for(i=0; i< v->n; i++){
        if(v->dados[i] == x) return 1;
    }
    return -1;
}

void remover_elemento(vetor *v, int i){
    v->dados[i] = v->dados[v->n-1];
    v->n--;
}

int acessar(vetor *v, int i) {
    return v->dados[i];
}

int tamanho(vetor *v) {
    return v->n;
}
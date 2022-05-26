
#include "vetor_dinamico.h"
#include <stdio.h>
#include <stdlib.h>




vetor* criar_vetor(int tam){
    vetor *v;
    v = (vetor*) malloc(sizeof(vetor));
    v->dados = (int*) malloc(tam * sizeof(int));
    v->n = 0;
    v->alocado = tam;
    return v;
}

void adicionar_elemento(vetor *v, int x){
    int i, *temp;
    if (v->n == v->alocado){
        temp = v->dados;
        v->alocado *= 2; //Dobrando tamanho do Vetor
        v->dados = (int*) malloc(v->alocado * sizeof(int));
        for(i=0; i < v->n; i++){
            v->dados[i] = temp[i];
        }
        free(temp);
    }
    v->dados[v->n] = x;
    v->n++;
}

void remover_elemento(vetor *v, int i){
    int j, *temp;
    for(; i < v->n-1; i++){
        v->dados[i] = v->dados[i+1];
    }
    (v->n)--;
    if (v->n < v->alocado/4 && v->alocado >= 4){
        temp = v->dados;
        v->alocado/=2;
        v->dados = (int) malloc(v->alocado * sizeof(int));
        for(j = 0; j< v->n; j++){
            v->dados[j] = temp[j];
        }
        free(temp);
    }
}
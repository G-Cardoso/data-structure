#include "lista_circular.h"
#include <stdlib.h>
#include <stdio.h>

No* criar_lista(){
    return NULL;
}

void destruir_lista (No **p){
    if(*p == NULL) return;
    No *q = (*p)->prox, *aux;
    while(q!=*p){
        aux = q;
        q = q->prox;
        free(aux);
    }
    free(*p);
    *p = NULL;
}

void imprimir_lista(No *p){
    No* q, *aux = p;
    if(p != NULL){
        for (q = p->prox; q!= aux; q = q->prox) printf("%d -> ", q->dado);
        printf("%d -> ", q->dado);
    }
    printf("NULL\n");
}

void adicionar_inicio(No** p, int x){
    No *q = (No*) malloc(sizeof(No));
    q->dado = x;
    if(*p == NULL){
        *p = q;
        q->prox = q;
    }else{
        q->prox = (*p)->prox;
        (*p)->prox = q;
    }
}

void adicionar_final(No **p, int x){
    No *q = (No*) malloc(sizeof(No));
    q->dado = x;
    if(*p == NULL){
        *p = q;
        q->prox = q;
    }else{
        q->prox = (*p)->prox;
        (*p)->prox = q;
        *p = q;
    }
}

int buscar_valor(No *p, int x){
    if(p == NULL) return -1;
    No *q = p;
    p = p->prox;
    while(p!=q){
        if(p->dado == x) return 1;
        p = p->prox;
    }
    if(p->dado == x) return 1;
    return 0;
}

void remover_inicio(No **p){
    if (*p == NULL) return;
    No* q = *p;
    if(q->prox==q){
        free(q);
        *p = NULL;
        return;
    }
    q = q->prox;
    (*p)->prox = q->prox;
    free(q);
}

void remover_final(No **p){
    if (*p == NULL) return;
    No* q = *p;
    if(q->prox == q){
        free(q);
        *p = NULL;
        return;
    }
    No *aux = q;
    while(q->prox != aux) q = q->prox;
    q->prox = aux->prox;
    *p = q;
    free(aux);
}

void remover_valor(No **p, int x){
    if(*p == NULL) return;
    No *q = *p;
    if(q->prox == q && q->dado == x){
        free(q);
        *p = NULL;
        return;
    }
    while(q->prox != *p && (q->prox)->dado != x)q = q->prox;
    if((q->prox)->dado == x){
        No *aux = q->prox;
        q->prox = aux->prox;
        if(*p == aux) *p = q;
        free(aux);
    }
}

int tamanho_lista(No *p){
    if(p == NULL) return 0;
    No *q = p;
    int tam = 1;
    for(p = p->prox; p != q; p = p->prox) tam++;
    return tam;
}

void decidir_vencedor(No **p){
    No* q = *p;
    int tamanho = tamanho_lista(*p);
    for(int i=0; i<tamanho; i++){
        if (q->dado%2==0){ // sentido horário

        }else{ // sentido anti-horário

        }
    }

}
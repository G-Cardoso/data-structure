#include "lista_ligada.h"
#include <stdlib.h>
#include <stdio.h>

No* criar_lista(){
    return NULL;
}

void destruir_iterativo(No **p){
    No *q;
    while(*p != NULL){
        q = *p;
        *p = (*p)->prox;
        free(q);
    }
}

void destruir_recursivo(No *p){
    if (p != NULL){
        destruir_recursivo(p->prox);
        free(p);
    }
}

void destruir_lista(No **p){
    destruir_iterativo(p);
    // destruir_recursivo(*p)
}

void imprimir_lista(No *p){
    No *q;
    for (q = p; q!= NULL; q = q->prox) printf("%d -> ", q->dado);
    printf("\nNULL\n");
}

void adicionar_inicio(No **p, int x){
    No *q;
    q = (No*) malloc(sizeof(No));
    if(q==NULL){
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    q->dado = x;
    q->prox = *p;
    *p = q;
}

void adicionar_final(No **p, int x){
    No *aux, *q;
    q = (No*) malloc(sizeof(No));
    q->dado = x;
    q->prox = NULL;
    if(*p == NULL) *p = q;
    else{
        aux = *p;
        while(aux->prox != NULL) aux = aux->prox;
        aux->prox = q;
    }
}

void adicionar_ordenado(No **p, int v){
    No *aux, *q = malloc(sizeof(No));
    if(q==NULL){
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    q -> dado = v;
    if(*p == NULL){
        q->prox = NULL;
        *p = q;
    }else if(q -> dado < (*p)->dado){
        q->prox = *p;
        *p = q;
    }
    else{
        aux = *p;
        while(aux->prox && q->dado > aux->prox->dado)
            aux = aux->prox;
        q->prox = aux->prox;
        aux->prox = q;
    }
}

int buscar_valor(No *p, int x) {// q recebe L
    while(p != NULL){
        if(p->dado == x) return 1; //true!
        p = p->prox;
    }
    return 0;//false == n˜ao encontrou
}

int buscar_valor_ordenado(No *p, int x){
    if(p == NULL) return 0;
    while(p->dado <= x && p->prox != NULL){
        if(p->dado == x) return 1;
        p = p->prox;
    }
    return 0;
}


void imprimir_recursivo(No *p){
    if (p != NULL){
        printf("%d -> ", p->dado);
        imprimir_recursivo(p->prox);
    }
    else printf("\nNULL\n");
}

void remover_inicio(No **p){
    No* q = *p;
    if(q==NULL) return;
    *p = q->prox;
    free(q);
}

void remover_final(No **p){
    No* q = *p;
    if(q==NULL) return;
    if(q->prox==NULL){
        *p = NULL;
        free(q);
        return;
    }
    while(q->prox->prox != NULL) q = q->prox;
    free(q->prox);
    q->prox = NULL;
}

void remover_valor(No **p, int v){
    No* q = *p;
    if(q==NULL) return;
    if(q->dado == v){
        *p = q->prox;
        free(q);
        return;
    }
    while(q->prox != NULL){
        if(q->prox->dado == v) break;
        q = q->prox;
    }
    if (q->prox == NULL) return;
    No* tmp = q->prox;
    q->prox = tmp->prox;
    free(tmp);
}



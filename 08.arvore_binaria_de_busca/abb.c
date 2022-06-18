#include <stdlib.h>
#include <stdio.h>
#include "abb.h"

No* criar_arvore(){
    return NULL;
}

void destruir_arvore(No **p){
    if (*p == NULL) return;
    destruir_arvore(&((*p)->esq));
    destruir_arvore(&((*p)->dir));
    free(*p);
    *p = NULL;
}

void imprimir_arvore(No *p, int h){
    int i;
    if (p != NULL){
        imprimir_arvore(p->dir, h+1);
        for(i=0; i<h; i++)printf("-");
        printf(" %d\n", p->chave);
        imprimir_arvore(p->esq, h+1);
    }
}

void imprimir_inordem(No *p){
    if (p != NULL){
        imprimir_inordem(p->esq);
        printf("%d", p->chave);
        imprimir_inordem(p->dir);
    }
}

No* buscar(No *p, int chave){
    if(p == NULL || chave == p->chave) return p;
    if(chave < p->chave) return buscar(p->esq, chave);
    return buscar(p->dir, chave);
}

No* inserir(No *p, int chave){
    if(p==NULL){
        No *novo;
        novo = (No*) malloc(sizeof(No));
        if(novo == NULL){
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        novo->esq = novo->dir = NULL;
        novo->chave = chave;
        return novo;
    }
    if(chave < p->chave) p->esq = inserir(p->esq, chave);
    else p->dir = inserir(p->dir, chave);
    return p;
}

No* minimo(No *p){
    if (p == NULL || p->esq == NULL) return p;
    return minimo(p->esq);
}

No* maximo(No *p){
    if (p == NULL || p->dir == NULL) return p;
    return maximo(p->dir);
}

No* ancestral_a_direita(No *x){
    if (x == NULL) return x;
    if (x->pai == NULL || x->pai->esq == x) return x->pai;
    else return ancestral_a_direita(x->pai);
}

No* sucessor(No *x){
    if (x->dir != NULL) return minimo(x->dir);
    else return ancestral_a_direita(x);
}

void remover_sucessor(No *p){
    No *min = p->dir;
    No *pai = p;
    while(min->esq != NULL){
        pai = min;
        min = min->esq;
    }
    if(pai->esq == min)
        pai->esq = min->dir;
    else {
        pai->dir = min->dir;
    }
    p->chave = min->chave;
    free(min);
}

No* remover_rec(No *p, int chave){
    if (p==NULL) return p;
    if (chave < p->chave) p->esq = remover_rec(p->esq, chave);
    else if(chave > p->chave) p->dir = remover_rec(p->dir, chave);
    else if (p->esq == NULL){//filho dir sucessor
        No *q = p->dir;
        free(p);
        return q;
    }
    else if(p->dir == NULL){//nao tem sucessor
        No *q = p->esq;
        free(p);
        return q;
    }
    else {
        remover_sucessor(p);
    }
    return p;
}

void remover(No **p, int chave){
    *p = remover_rec(*p, chave);
}


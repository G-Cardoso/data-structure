#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"

NoArvore* criar_no(int x, NoArvore *l, NoArvore *r){
    NoArvore *noArvore = (NoArvore*) malloc(sizeof(NoArvore));
    if(noArvore==NULL){
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    noArvore->dado = x;
    noArvore->esq = l;
    noArvore->dir = r;
    return noArvore;
}

void destruir_arvore(NoArvore **raiz){
    if (*raiz == NULL) return;
    destruir_arvore(&((*raiz)->esq));
    destruir_arvore(&((*raiz)->dir));
    free(*raiz);
    *raiz = NULL;
}

void printnode(int x, int h){
    int i;
    for(i=0; i<h; i++) printf("-");
    printf("%2d\n", x);
}

void print(NoArvore *p, int h){
    if (p == NULL) return;
    print(p->dir, h+1);
    printnode(p->dado, h);
    print(p->esq, h+1);
}

void imprimir_arvore(NoArvore *raiz){
    print(raiz, 0);
}

NoArvore* procurar_no(NoArvore *raiz, int x){
    if(raiz == NULL || raiz->dado == x) return raiz;
    NoArvore *esq = procurar_no(raiz->esq, x);
    if(esq != NULL) return esq;
    return procurar_no(raiz->dir, x);
}

int numero_nos(NoArvore *raiz){
    if (raiz == NULL) return 0;
    return numero_nos(raiz->esq) + numero_nos(raiz->dir) + 1;
}

int altura(NoArvore *raiz){
    int h_esq, h_dir;
    if (raiz == NULL) return 0;
    h_esq = altura(raiz->esq);
    h_dir = altura(raiz->dir);
    return (h_esq > h_dir ? h_esq : h_dir) + 1;
}

void pre_ordem(NoArvore *raiz){
    if (raiz != NULL){
        printf("%d ", raiz->dado);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}

void pos_ordem(NoArvore *raiz){
    if(raiz != NULL){
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        printf("%d ", raiz->dado);
    }
}

void in_ordem(NoArvore *raiz){
    if(raiz != NULL){
        in_ordem(raiz->esq);
        printf("%d ", raiz->dado);
        in_ordem(raiz->dir);
    }
}

//Percurso em Largura: Utilizando TAD de Fila.
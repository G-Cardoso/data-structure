#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

//Dados
typedef struct noArvore{
    int dado;
    struct noArvore *esq, *dir;
} NoArvore;

//Funções
NoArvore* criar_no(int x, NoArvore *l, NoArvore *r);

void destruir_arvore(NoArvore **raiz);

void imprimir_arvore(NoArvore *raiz);

NoArvore* procurar_no(NoArvore *raiz, int x);

int numero_nos(NoArvore *raiz);

int altura(NoArvore *raiz);

void pre_ordem(NoArvore *raiz);

void pos_ordem(NoArvore *raiz);

void in_ordem(NoArvore *raiz);

void percurso_em_largura(NoArvore *raiz);

#endif
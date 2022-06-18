#ifndef ABB_H
#define ABB_H

//Dados
typedef struct no{
    int chave;
    struct no *esq, *dir, *pai;
} No;

//Funções
No* criar_arvore();
void destruir_arvore(No **p);

void imprimir_arvore(No *p, int h);
void imprimir_inordem(No *p);

No* inserir(No *p, int chave);
void remover(No **p, int chave);

No* buscar(No *p, int chave);

#endif
#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

//Dados
typedef struct no {
    int dado;
    struct no *prox;
} No;

//Funções
No* criar_lista();
void destruir_lista(No **L);

//Imprimir
void imprimir_lista(No *L);

//Adicionar 
void adicionar_inicio(No **L, int x);
void adicionar_final(No **L, int x);

//Remover
void remover_inicio(No **L);
void remover_final(No **L);
void remover_valor(No **L, int x);

//Buscar
int buscar_valor(No *L, int x);

//Tamanho
int tamanho_lista(No *L);

#endif
#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

//Dados
typedef struct no {
    int dado_i, dado_j;
    struct no *prox;
} No;

//Funções
No* criar_lista();
void destruir_lista(No **L);

//Imprimir
void imprimir_lista(No *L);

//Adicionar 
void adicionar_inicio(No **L, int i, int j);
void adicionar_final(No **L, int i, int j);

//Remover
void remover_inicio(No **L);
void remover_final(No **L);
void remover_valor(No **L, int i, int j);

//Buscar
int buscar_valor(No *L, int i, int j);
void acessar_primeiro(No *L, int* i, int* j);

//Tamanho
int tamanho_lista(No *L);

#endif
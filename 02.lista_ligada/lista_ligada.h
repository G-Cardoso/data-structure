#ifndef LISTA_LIGADA_H
#define LISTA_LIGADA_H

//Dados
typedef struct no{
    int dado;
    struct no *prox;
} No;

//Funções:
No* criar_lista();
void destruir_lista(No **L);

void imprimir_lista(No *L);

//Adicionar
void adicionar_inicio(No **L, int x);
void adicionar_final(No **L, int x);
void adicionar_ordenado(No **L, int x);

//Remover
void remover_inicio(No **L);
void remover_final(No **L);
void remover_valor(No **L, int x);

//Buscar
int buscar_valor(No *L, int x);
int buscar_valor_ordenado(No *L, int x);

#endif
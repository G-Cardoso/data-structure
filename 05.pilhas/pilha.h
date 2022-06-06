#ifndef PILHA_H
#define PILHA_H

//Dados
#define MAX 100

//dados
typedef struct {
    int topo, N;
    int *dados;
} Pilha;

//Funções
Pilha* pilha_criar();
void pilha_destruir(Pilha **P);

//Adicionar
void pilha_adicionar(Pilha **P, int x);

//Acessar
int pilha_topo(Pilha *P);

//Remover
void pilha_remover(Pilha **P);

//Extra
int pilha_tamanho(Pilha *P);

#endif
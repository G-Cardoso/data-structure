#include <stdio.h>
#include "pilha.h"

int main(){
    int i, num;
    Pilha *P = pilha_criar();
    scanf("%d", &num);
    for(i=1; i<=num; i++) pilha_adicionar(&P, i);
    while(pilha_tamanho(P)>0){
        printf("%d\n", pilha_topo(P));
        pilha_remover(&P);
    }
    pilha_destruir(&P);
    return 0;
}
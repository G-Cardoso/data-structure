#include <stdio.h>
#include "fila.h"

int main(){
    int i, num;
    Fila *F = fila_criar();
    scanf("%d", &num);
    for(i=1; i<=num; i++) fila_adicionar(&F, i);
    while(fila_tamanho(F)>0){
        printf("%d\n", fila_topo(F));
        fila_remover(&F);
    }
    fila_destruir(&F);
    return 0;
}
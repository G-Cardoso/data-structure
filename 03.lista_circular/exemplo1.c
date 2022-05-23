#include <stdio.h>
#include "lista_circular.h"

int main(){
    int i, num;
    No *L = criar_lista();
    scanf("%d", &num);
    for(i=1; i<=num; i++) adicionar_final(&L, i);
    imprimir_lista(L);
    while(tamanho_lista(L)>0){
        scanf("%d", &i);
        remover_valor(&L, i);
        imprimir_lista(L);
        printf("Tamanho -> [%d]\n", tamanho_lista(L));
    }
    destruir_lista(&L);
    return 0;
}
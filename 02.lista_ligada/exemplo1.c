#include <stdio.h>
#include "lista_ligada.h"

int main(){
    int num;
    No *L = criar_lista();
    do{
        scanf("%d", &num);
        if (num>=0) adicionar_ordenado(&L, num);
    }while(num>=0);
    imprimir_lista(L);
    int achou = buscar_valor_ordenado(L, 10);
    printf("Achou? %d", achou);
    destruir_lista(&L);
return 0;
}
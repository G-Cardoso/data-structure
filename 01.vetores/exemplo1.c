#include <stdio.h>
#include "vetor.h"

int main(){
    vetor *v;
    v = criar_vetor(100);
    int i, num;
    scanf("%d", &num);
    for(i=1; i<=num; i++) adicionar_elemento(v, i);
    while(tamanho(v)>0){
        printf("%d -> ", acessar(v, 0));
        remover_elemento(v, 0);
    }
    printf("FIM\n");
    destruir_vetor(v);
    return 0;
}
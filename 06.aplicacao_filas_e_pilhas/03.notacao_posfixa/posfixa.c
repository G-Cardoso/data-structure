#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../05.pilhas/pilha.h"

int posfixa(char **s, int n);

int main(int argc, char **argv){
    if(argc<2){
        printf("usage %s \"sequence\"\n", argv[0]);
        return 1;
    }
    printf("%d\n", posfixa(&argv[1], argc-1));
    return 0;
}

int posfixa(char **s, int n){
    Pilha *P = pilha_criar();
    int aux1,aux2;

    for(int i=0; i<n; i++){
        if(s[i][0]=='+' || s[i][0]=='-' || s[i][0]=='*' || s[i][0]=='/'){
            aux1 = pilha_topo(P);
            pilha_remover(&P);
            aux2 = pilha_topo(P);
            pilha_remover(&P);

            switch (s[i][0]) {
                case '+':
                    pilha_adicionar(&P, aux1+aux2);
                    break;
                case '-':
                    pilha_adicionar(&P, aux1-aux2);
                    break;
                case '*':
                    pilha_adicionar(&P, aux1*aux2);
                    break;            
                default:
                    pilha_adicionar(&P, aux2/aux1);
                    break;
            }
        }else{
            pilha_adicionar(&P, atoi(s[i]));
        }
    }
    int retorno = pilha_topo(P);
    pilha_destruir(&P);
    return retorno;
}
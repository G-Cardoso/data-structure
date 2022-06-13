#include <stdio.h>
#include <string.h>
#include "../../05.pilhas/pilha.h"

int balanceada(char *s);

int main(int argc, char **argv){
    if(argc!=2){
        printf("usage %s \"sequence\"\n", argv[0]);
        return 1;
    }
    printf("%s\n", argv[1]);
    if(balanceada(argv[1])) printf("SIM\n");
    else printf("NAO\n");
    return 0;
}

int balanceada(char *s){
    int i, ok = 1;
    int n = strlen(s);
    Pilha *P = pilha_criar();
    for(i=0; i<n && ok; i++){
        if(s[i]=='(') pilha_adicionar(&P, s[i]);
        else if(s[i]== ')'){
            if(pilha_tamanho(P)==0) ok = 0;
            else{
                //Tirar dúvida com Professor
                char c = pilha_topo(P);
                pilha_remover(&P);
            }
        }
    }
    if(pilha_tamanho(P)>0) ok =0;
    pilha_destruir(&P);
    return ok;
}
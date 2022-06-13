#include <stdio.h>
#include <stdlib.h>
#include "../../04.filas/fila.h"

int** alocar_matriz(int n, int e);
void ler_matriz(int **M, int e);
void desalocar_matriz(int **M, int l);
void imprimir_matriz(int **M, int l, int c);
void distancia(int **M, int n, int *dist, int c);

int main(){
    int n, e, i, j;
    scanf("%d %d", &n, &e);
    int **M = alocar_matriz(n,n);
    ler_matriz(M,e);
    int **dist = alocar_matriz(n,n);
    for(i=0;i<n;i++){//Calculando Distâncias
        distancia(M,n,dist[i],i);
    }
    imprimir_matriz(dist, n, n);
    desalocar_matriz(dist, n);
    desalocar_matriz(M, n);
    return 0;
}

int** alocar_matriz(int n, int e){
    int i, j;
    int **M = (int**) malloc(n*sizeof(int*));
    for(i=0; i<n; i++){
        M[i] = (int*) malloc(n*sizeof(int));
        for(j=0; j<n; j++){
            M[i][j] = 0;
        }
    }
    return M;
}

void ler_matriz(int **M, int e){
    int i, j, x, y;
    for(int i=0; i<e; i++){
        scanf("%d %d", &x, &y);
        M[x][y] = 1;
    }
}

void desalocar_matriz(int **M, int l){
    int i;
    for(i=0;i<l;i++){
        free(M[i]);
    }
    free(M);
}

void imprimir_matriz(int **M, int l, int c){
    int i,j;
    for(i=0; i<l; i++){
        for(j=0; j<c; j++){
            printf("%d ",M[i][j]);
        }
        printf("\n");
    }
}

void distancia(int **M, int n, int *dist, int c){
    int i, j;
    for(i=0; i < n; i++){
        dist[i] = n;
    }
    dist[c]=0;

    Fila *F = fila_criar();
    fila_adicionar(&F, c);

    while(fila_tamanho(F)>0){
        i = fila_topo(F);
        fila_remover(&F);
        for(j=0; j<n; j++){
            if(M[i][j] == 1 && dist[j] >= n){
                dist[j] = dist[i]+1;
                fila_adicionar(&F, j);
            }
        }
    }
    fila_destruir(&F);
}
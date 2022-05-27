#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

#define MAX_ELEMENTOS 100

int main(){
    int H, W;
    int **mat;
    int **mat_caracteres;
    scanf("%d %d", &H, &W);
    int caracter = 97;//a,b,c,d...
    
    Fila* PQ[MAX_ELEMENTOS];
    
    mat = malloc (H * sizeof (int*)) ;
    mat_caracteres = malloc (H * sizeof (int*));

    // aloca cada uma das Hhas (vetores de W inteiros)
    for (int i=0; i < H; i++){
        mat[i] = malloc (W * sizeof (int));
        mat_caracteres[i] = malloc (W * sizeof (int));
    }

    // percorre a matriz
    for (int i=0; i < H; i++){
        for (int j=0; j < W; j++){
            scanf("%d",&mat[i][j]);
            mat_caracteres[i][j] = (int) '_';//Iniciando Matriz de resultados com caracter _ (underline)
        }
    }

    //Criando vetor de Filas
    for(int i = 0; i< MAX_ELEMENTOS; i++){
        PQ[i] = fila_criar();
    }

    //descobrindo dissipadores:
    for (int i=0; i < H; i++){
        for (int j=0; j < W; j++){
            int acc = 0;
            
            if(i>0){//verifica cima
                acc+= mat[i][j]>mat[i-1][j];
            }
            if(j>0){//verifica esquerda
                acc+= mat[i][j]>mat[i][j-1];
            }
            if(j<W-1){//verifica direita
                acc+= mat[i][j]>mat[i][j+1];
            }
            if(i<H-1){//verifica baixo
                acc+= mat[i][j]>mat[i+1][j];
            }
            if(acc==0){
                //Encontrando Dissipadores
                fila_adicionar(&PQ[mat[i][j]],i,j);
                mat_caracteres[i][j] = caracter++;
            }
        }
    }

    for(int k=0; k < MAX_ELEMENTOS; k++){
        while(fila_tamanho(PQ[k])>0){
            int pos_i, pos_j;
            fila_topo(PQ[k], &pos_i, &pos_j); //pegar as posições X e Y
            fila_remover(&PQ[k]);

            if(mat_caracteres[pos_i][pos_j]>=97 && mat_caracteres[pos_i][pos_j]<=122){//verifica os rotulos
                if(pos_i<H-1 && mat_caracteres[pos_i+1][pos_j]=='_'){//verificando baixo
                    if(mat[pos_i][pos_j]<mat[pos_i+1][pos_j]){
                        // printf("%d < %d \n",mat[pos_i][pos_j],mat[pos_i+1][pos_j]);
                        // printf("MAT_CHAR[%d][%d](%c) = MAT_CHAR[%d][%d](%c) \n",pos_i+1,pos_j,mat_caracteres[pos_i+1][pos_j],pos_i,pos_j,mat_caracteres[pos_i][pos_j]);
                        mat_caracteres[pos_i+1][pos_j] = mat_caracteres[pos_i][pos_j];
                        fila_adicionar(&PQ[mat[pos_i+1][pos_j]],pos_i+1,pos_j);
                    }
                }
                if(pos_j<W-1 && mat_caracteres[pos_i][pos_j+1]=='_'){//verificando direita
                    if(mat[pos_i][pos_j]<mat[pos_i][pos_j+1] && mat_caracteres[pos_i][pos_j+1]=='_'){
                        // printf("%d < %d \n",mat[pos_i][pos_j],mat[pos_i][pos_j+1]);
                        // printf("MAT_CHAR[%d][%d](%c) = MAT_CHAR[%d][%d](%c) \n",pos_i,pos_j+1,mat_caracteres[pos_i][pos_j+1],pos_i,pos_j,mat_caracteres[pos_i][pos_j]);
                        mat_caracteres[pos_i][pos_j+1] = mat_caracteres[pos_i][pos_j];
                        fila_adicionar(&PQ[mat[pos_i][pos_j+1]],pos_i,pos_j+1);
                    }
                }
                if(pos_j>0 && mat_caracteres[pos_i][pos_j-1]=='_'){//verificando esquerda
                    if(mat[pos_i][pos_j]<mat[pos_i][pos_j-1]){
                        // printf("%d < %d \n",mat[pos_i][pos_j],mat[pos_i][pos_j-1]);
                        // printf("MAT_CHAR[%d][%d](%c) = MAT_CHAR[%d][%d](%c) \n",pos_i,pos_j-1,mat_caracteres[pos_i][pos_j-1],pos_i,pos_j,mat_caracteres[pos_i][pos_j]);
                        mat_caracteres[pos_i][pos_j-1] = mat_caracteres[pos_i][pos_j];
                        fila_adicionar(&PQ[mat[pos_i][pos_j-1]],pos_i,pos_j-1);
                    }
                }
                if(pos_i>0 && mat_caracteres[pos_i-1][pos_j]=='_'){//verificando cima
                    if(mat[pos_i][pos_j]<mat[pos_i-1][pos_j]){
                        // printf("%d < %d \n",mat[pos_i][pos_j],mat[pos_i-1][pos_j]);
                        // printf("MAT_CHAR[%d][%d](%c) = MAT_CHAR[%d][%d](%c) \n",pos_i-1,pos_j,mat_caracteres[pos_i-1][pos_j],pos_i,pos_j,mat_caracteres[pos_i][pos_j]);
                        mat_caracteres[pos_i-1][pos_j] = mat_caracteres[pos_i][pos_j];
                        fila_adicionar(&PQ[mat[pos_i-1][pos_j]],pos_i-1,pos_j);
                    }
                }                
            }
        }
    }

    //imprimindo matriz resultante
    for(int pos_i = 0; pos_i < H; pos_i++){
        for(int pos_j = 0; pos_j < W; pos_j++){
            printf("%c ", mat_caracteres[pos_i][pos_j]);
        }
        printf("\n"); 
    }
    
    //Destruindo elementos:
    for(int i = 0; i< MAX_ELEMENTOS; i++){
        fila_destruir(&PQ[i]);
    }

    free(*PQ);
    
    for (int i=0; i < H; i++){
        free(mat[i]);
        free(mat_caracteres[i]);
    }
    free(mat);
    free(mat_caracteres);

    return 0;
}
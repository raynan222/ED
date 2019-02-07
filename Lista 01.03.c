#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

#define RAND_MAX 100
#define ABSURDO 100000000

/*
Ler duas matrizes A e B, de duas dimensões, sendo a matriz A de 5X4 (5 linhas e 4 colunas)
e a matriz B de 4X3 (quatro linhas e três colunas). Apresentar a matriz C como resultado da
multiplicação das matrizes A e B. Condição para multiplicação: o número de colunas de A
tem que ser igual ao número de linhas de B.
*/

void multiplicamatrix(int matriz1[5][4],int matriz2[4][3],int matriz3[4][3]);
void preenchermatrix(int matriz[][4], int tcoluna, int tlinha);

int main()
{
    int a[5][4], b[4][3], c[4][3], i, j;
    
    srand(time(0));

    preenchermatrix(a,5,4);
    preenchermatrix(b,4,3);
    multiplicamatrix(a,b,c);
    
    for(i=0;i<5;i++){
        for(j=0;j<4;j++){
            printf("%3d ",a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(i=0;i<4;i++){
        for(j=0;j<3;j++){
            printf("%3d ",b[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(i=0;i<4;i++){
        for(j=0;j<3;j++){
            printf("%3d ",c[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}

void preenchermatrix(int matriz[][4], int tcoluna, int tlinha){
    int i,j;
    srand(time(0));
    for(i=0;i<=tcoluna;i++){
        for(j=0;j<=tlinha;j++){
            matriz[i][j]=rand()/ABSURDO;
        }
    }
}

void multiplicamatrix(int matriz1[5][4],int matriz2[4][3],int matriz3[4][3]){
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<3;j++){
            matriz3[i][j]=(matriz1[i][j]*matriz2[i][j]);
        }
    }
}

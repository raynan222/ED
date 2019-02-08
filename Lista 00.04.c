#include<stdio.h>

/*
Desenvolva um algoritmo que, determine se um determinado número N informado é
primo ou não. Se sim, que encontre e informe os dois primos antecessores de N e os dois
primos sucessores de N. O algoritmo só encerra quando for informado um número N
primo.
*/


int verificaPrimo(int recebido);
int acharPrimosAnteriores(int primo);
int acharPrimosPosteriores(int primo);

int main() {
 
    int verificando, j, flag=0;
    int matriz[5]={2, 3, 5, 7, 11};
     
    printf("Digite um número: ");
    scanf("%d", &verificando);
    printf("\n");
    if(verificando==2){
        printf("%3d %3d %3d\n",matriz[0],matriz[1],matriz[2]);
    }
    if(verificando==3){
        printf("%3d %3d %3d %3d\n",matriz[0],matriz[1],matriz[2],matriz[3]);
    }
    if(verificando==5){
        printf("%3d %3d %3d %3d %3d\n",matriz[0],matriz[1],matriz[2],matriz[3],matriz[4]);
    }
    if(verificaPrimo(verificando)==1 && verificando!=2 && verificando!=3 && verificando!=5){
        matriz[1]=acharPrimosAnteriores(verificando);
        matriz[0]=acharPrimosAnteriores(matriz[1]);
        matriz[2]=verificando;
        matriz[3]=acharPrimosPosteriores(verificando);
        matriz[4]=acharPrimosPosteriores(matriz[3]);
        for(j=0;j<5;j++){
            printf("%3d ",matriz[j]);
        }
        printf("\n");
    }
    if(verificaPrimo(verificando)==0 && verificando!=2 && verificando!=3 && verificando!=5){
        printf("%3d Não é um número primo.\n", verificando);
    }
    return 0;
}

int verificaPrimo(int recebido){
    int i;
    if (recebido <= 1){
        return 0;
    }
    if (recebido % 2 == 0 && recebido > 2){
        return 0;
    }
    for(i = 3; i < recebido / 2; i+= 2){
        if (recebido % i == 0){
            return 0;
        }
    }
    return 1;
}

int acharPrimosAnteriores(int primo){
    int aux=primo-2;
    while(verificaPrimo(aux)!=1){
        aux-=2;
    }
    return aux;
}

int acharPrimosPosteriores(int primo){
    int aux=primo+2;
    while(verificaPrimo(aux)!=1){
        aux+=2;
    }
    return aux;
}

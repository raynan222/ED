#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

#define RAND_MAX 100
#define ABSURDO 20000000

/*
Elabore um algoritmo que armazene 30 valores inteiros num vetor; segundo a
seguinte lei de formação: Se o índice do vetor for par, o valor digitado deverá ser
multiplicado por 2, caso contrário por 5. A seguir efetue uma pesquisa binária no
vetor.
*/

int main()
{
    int vetor[30],i,aux,flag;
    
    srand(time(0));
    
    for(i=0;i<30;i++){
        if(i%2==0){
           vetor[i]=(rand()/ABSURDO)*2;
        }
        if(i%2!=0){
           vetor[i]=(rand()/ABSURDO)*5;
        }
    }
    
    printf("Qual número deseja encontrar: ");
    scanf("%u",&aux);
    
    for(i=0;i<30;i++){
        if(vetor[i]==aux){
            printf("\nNúmero %u encontrado na posição [%u] do vetor.",vetor[i],i);
            flag=1;
            break;
        }
    }
    
    if(flag!=1){
        printf("\nNúmero %u não encontrado no vetor.\n",aux);
    }

    return 0;
}

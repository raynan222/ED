#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Suponha que existam 02 vetores A e B do tipo inteiro com 25 elementos inteiros
cada. Elabore um algoritmo que construa um vetor C a partir da junção de A e B. A
seguir efetue uma pesquisa sequencial no vetor no vetor C.
*/

int main()
{
    int a[25],b[25],c[50],aux,i,indexrandomico,flag;
    srand(time(0));
    
    for (i=0; i<25; i++){
    a[i] = i;
    }
    
    for (aux=0; aux<25; i++, aux++){
    b[aux] = i;
    }
    
    for (i=0; i<25; i++){
    indexrandomico=rand()%25;
    aux=a[i];
    a[i]=a[indexrandomico];
    a[indexrandomico]=aux;
    }
    
    for (i=0; i<25; i++){
    indexrandomico=rand()%25;
    aux=b[i];
    b[i]=b[indexrandomico];
    b[indexrandomico]=aux;
    }
    
    for(i=0;i<25;i++){
        c[i]=a[i];
    }
    
    for(i=0,aux=25;i<25;i++,aux++){
        c[aux]=b[i];
    }
    
    printf("Qual número deseja encontrar: ");
    scanf("%d",&aux);
    
    for(i=0;i<50;i++){
        if(c[i]==aux){
            printf("\nNúmero %d encontrado na posição [%d] do vetor.",c[i],i);
            flag=1;
            break;
        }
    }
    
    if(flag!=1){
        printf("\nNúmero %d não encontrado no vetor.",aux);
    }
    
    return 0;
}

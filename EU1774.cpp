#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
  
struct Aresta 
{ 
    int origem, destino, distancia; 
};
  

struct Grafo 
{ 
    int V, A; 
    struct Aresta* aresta; 
};
  
struct Grafo* criarGrafo(int V, int A) 
{ 
    struct Grafo* grafo = (struct Grafo*)malloc(sizeof(struct Grafo)); 
    grafo->V = V; 
    grafo->A = A; 
  
    grafo->aresta = (struct Aresta*)malloc(A * sizeof(struct Aresta)); 
    return grafo; 
};
  
struct subsequencia 
{ 
    int parent; 
    int rank; 
};
  
int find(struct subsequencia subsequencias[], int i) 
{ 
    if (subsequencias[i].parent != i) 
        subsequencias[i].parent = find(subsequencias, subsequencias[i].parent); 
  
    return subsequencias[i].parent; 
};
 
void Union(struct subsequencia subsequencias[], int x, int y) 
{ 
    int xraiz = find(subsequencias, x); 
    int yraiz = find(subsequencias, y); 
  
    if (subsequencias[xraiz].rank < subsequencias[yraiz].rank) 
        subsequencias[xraiz].parent = yraiz; 
    else if (subsequencias[xraiz].rank > subsequencias[yraiz].rank) 
        subsequencias[yraiz].parent = xraiz; 
  
    else
    { 
        subsequencias[yraiz].parent = xraiz; 
        subsequencias[xraiz].rank++; 
    } 
};
  
int Compara(const void* a, const void* b) 
{ 
    struct Aresta* a1 = (struct Aresta*)a; 
    struct Aresta* b1 = (struct Aresta*)b; 
    return a1->distancia > b1->distancia; 
}; 
  
void Kruskal(struct Grafo* grafo) 
{ 
    int V = grafo->V; 
    struct Aresta resultado[V]; 
    int e = 0;  
    int i = 0;  
  	int soma = 0;
 
    qsort(grafo->aresta, grafo->A, sizeof(grafo->aresta[1]), Compara); 
  
    struct subsequencia *subsequencias = 
        (struct subsequencia*) malloc( V * sizeof(struct subsequencia) ); 
  
 
    for (int v = 0; v < V; ++v) 
    { 
        subsequencias[v].parent = v; 
        subsequencias[v].rank = 0; 
    } 
  
    while (e < V - 1) 
    { 

        struct Aresta prox_aresta = grafo->aresta[i++]; 
  
        int x = find(subsequencias, prox_aresta.origem); 
        int y = find(subsequencias, prox_aresta.destino); 
  
        if (x != y) 
        { 
            resultado[e++] = prox_aresta; 
            Union(subsequencias, x, y); 
        } 

    } 

    printf("Following are the arestas in the constructed MST\n"); 
    for (i = 0; i < e; ++i) 
    	soma = soma + resultado[i].distancia;
    	printf("%d soma",soma);
        //printf("%d -- %d == %d\n", resultado[i].origem, resultado[i].destino, resultado[i].distancia); 
    return; 
}; 


int main() 
{ 

    int V, A, orig, dest, dist, cont=0;
    scanf("%d %d", &V, &A);
    struct Grafo* grafo = criarGrafo(V, A);
    
    while(A--){
    	scanf("%d %d %d", &orig, &dest, &dist);
    	grafo->aresta[cont].origem = orig; 
   		grafo->aresta[cont].destino = dest; 
   		grafo->aresta[cont].distancia = dist; 
   		cont++;
	}
    Kruskal(grafo); 
    
    return 0; 
} 

// C++ program for Kruskal's algorithm to find Minimum Spanning Tree 
// of a given connected, undirected and distanciaed grafo 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
  
// a structure to represent a distanciaed aresta in grafo 
struct Aresta 
{ 
    int origem, destino, distancia; 
}; 
  
// a structure to represent a connected, undirected 
// and distanciaed grafo 
struct Grafo 
{ 
    // V-> Number of arestas, A-> Number of arestas 
    int V, A; 
  
    // grafo is represented as an array of arestas.  
    // Since the grafo is undirected, the aresta 
    // from origem to destino is also aresta from destino 
    // to origem. Both are counted as 1 aresta here. 
    struct Aresta* aresta; 
}; 
  
// Creates a grafo with V arestas and A arestas 
struct Grafo* criarGrafo(int V, int A) 
{ 
    struct Grafo* grafo = new Grafo; 
    grafo->V = V; 
    grafo->A = A; 
  
    grafo->aresta = new Aresta[A]; 
  
    return grafo; 
} 
  
// A structure to represent a subsequencia for union-find 

  
// A utility function to find set of an element i 
// (uses path compression technique) 
int find(int parent[], int i) 
{ 
    // find raiz and make raiz as parent of i  
    // (path compression) 
    if (parent[i] == -1) 
        return i; 
    return find(parent, parent[i]); 

} 
// A function that does union of two sets of x and y 
// (uses union by rank) 
void Union(int parent[], int x, int y){ 
   	int xset = find(parent, x); 
    int yset = find(parent, y); 
    if(xset!=yset){ 
       parent[xset] = yset; 
    } 
    
	} 
  
// Compare two arestas according to their distancias. 
// Used in qsort() for sorting an array of arestas 
int Compara(const void* a, const void* b) 
{     

    struct Aresta* a1 = (struct Aresta*)a; 
    struct Aresta* b1 = (struct Aresta*)b; 
    return a1->distancia > b1->distancia; 

} 
  
// The main function to construct MST using Kruskal's algorithm 
void Kruskal(struct Grafo* grafo) 
{ 
    int V = grafo->V; 
    struct Aresta resultado[V];  // Tnis will store the resultadoant MST 
    int e = 0;  // An index variable, used for resultado[] 
    int i = 0;  // An index variable, used for sorted arestas 
  	int soma = 0;
    // Step 1:  Sort all the arestas in non-decreasing  
    // order of their distancia. If we are not allowed to  
    // change the given grafo, we can criar a copy of 
    // array of arestas 
    qsort(grafo->aresta, grafo->A, sizeof(grafo->aresta[0]), Compara); 
  
    // Allocate memory for creating V ssubsequencias 
    int *parent = (int*) malloc( grafo->V * sizeof(int) ); 
    memset(parent, -1, sizeof(int) * grafo->V); 


    // Number of arestas to be taken is equal to V-1 
    
    while (e < V - 1) 
    { 
        // Step 2: Pick the smallest aresta. And increment  
        // the index for prox iteration 
        struct Aresta prox_aresta = grafo->aresta[i++]; 

        int x = find(parent, prox_aresta.origem); 
        int y = find(parent, prox_aresta.destino); 
  
  	
  
        // If including this aresta does't cause cycle, 
        // include it in resultado and increment the index  
        // of resultado for prox aresta 
        if (x != y) 
        { 
            resultado[e++] = prox_aresta; 
            Union(parent, x, y); 
        } 
        // Alse discard the prox_aresta 
    } 
  
    // print the contents of resultado[] to display the 
    // built MST 
    printf("Following are the arestas in the constructed MST\n"); 
    for (i = 0; i < e; ++i) 
    	soma = soma + resultado[i].distancia;
    	printf("%d soma",soma);
        //printf("%d -- %d == %d\n", resultado[i].origem, resultado[i].destino, resultado[i].distancia); 
    return; 
} 



int main() 
{ 
    /* Let us create following distanciaed grafo 
             10 
        0--------1 
        |  \     | 
       6|   5\   |15 
        |      \ | 
        2--------3 
            4       */
    int V, A, orig, dest, dist, cont=0;
    scanf("%d %d", &V, &A);
    struct Grafo* grafo = criarGrafo(V, A);
    
    while(A--){
    	scanf("%d %d %d", &orig, &dest, &dist);
    	grafo->aresta[cont].origem = dest; 
   		grafo->aresta[cont].destino = orig; 
   		grafo->aresta[cont].distancia = dist; 
   		cont++;
	}
    Kruskal(grafo); 
  
    return 0; 
} 

#include <stdio.h>
#include <stdlib.h>

typedef struct grafo{
    int numVertice;
    int **matriz_adj;
    
}tipo_grafo;

tipo_grafo *criaGrafo(int nVert){
    
    int i, j;
    
    tipo_grafo *G = malloc(sizeof(tipo_grafo));
    G->numVertice = nVert;
    
    G->matriz_adj = (int**) malloc(nVert*sizeof(int *));
    
    for (i = 0; i < nVert; i++)
        G->matriz_adj[i] = (int *) malloc(nVert*sizeof(int));
        
    for (i = 0; i < nVert; i++)
        for (j = 0; j < nVert; j++)
            G->matriz_adj[i][j] = 0;
    
    return G;
}

void mostra_grafo(tipo_grafo *G){
    int i, j;
    
    printf("\n Mostrando a matriz de adj do grafo\n   ");

    for (i = 0; i< G->numVertice; i++)
        printf("%d ", i);
    printf("\n");

    for (i = 0; i< G->numVertice; i++){
        printf("%d ", i);
        for (j = 0; j< G->numVertice; j++)
            printf(" %d", G->matriz_adj[i][j]);
        
        printf("\n");
    }
}


void addArestaGrafo(tipo_grafo *G, int origem, int destino, int peso){
    G->matriz_adj[origem][destino] = peso;
    G->matriz_adj[destino][origem] = peso;
}

void removeArestaGrafo(tipo_grafo *G, int origem, int destino){
    G->matriz_adj[origem][destino] = 0;
    G->matriz_adj[destino][origem] = 0;
}
void addArestaDigrafo(tipo_grafo *G, int origem, int destino, int peso){
    G->matriz_adj[origem][destino] = peso;
}

void removeArestaDigrafo(tipo_grafo *G, int origem, int destino){
    G->matriz_adj[origem][destino] = 0;
}

tipo_grafo *liberaGrafo(tipo_grafo *G){
    if (G){
        for (int i = 0; i < G->numVertice; i++)
            free(G->matriz_adj[i]);
        free(G->matriz_adj);
        
        free(G);
    }
    return NULL;
}

int main(){
    tipo_grafo *G = criaGrafo(5);

    addArestaDigrafo(G, 0, 2, 6);
    addArestaDigrafo(G, 0, 1, 2);
    addArestaDigrafo(G, 0, 3, 7);
    addArestaDigrafo(G, 2, 4, 1);
    addArestaDigrafo(G, 1, 4, 6);
    addArestaDigrafo(G, 3, 4, 5);
    addArestaDigrafo(G, 1, 3, 3);
    
    //removeArestaGrafo(G, 2, 1);
    mostra_grafo(G);
    
    
    G = liberaGrafo(G);
    return 0;
}


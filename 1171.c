#include <stdio.h>
#include <stdlib.h>

void merge(int vetor[], int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];
    }
    
    free(vetAux);
}

void mergeSort(int vetor[], int comeco, int fim){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}

int main()
{
    int tamanho;
   
    printf("O Tamanho do vetor é :");
    scanf("%d", &tamanho);
    int v[tamanho];
    
    for(int i = 0; i < tamanho; i++)
        scanf("%d", &v[i]);

    mergeSort(v, 0 , tamanho-1 );
    
    int cont = 1;
    for(int i = 0; i < tamanho-1; i++){
        if(v[i] == v[i+1]){
            cont++;
        }else{
            printf("%d aparece %d vez(es)\n", v[i] , cont);
           cont = 1;
        }
        printf("%d aparece %d vez(es)\n", v[i-1] , cont);
    }
    
    
    return 0;
}

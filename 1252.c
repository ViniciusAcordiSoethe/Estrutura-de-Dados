#include <stdio.h>
#include <stdlib.h>

int compara(int v1 , int v2 , int mod){
    if(v1%mod < v2%mod)
        return 1;
    if(v1%mod > v2%mod)
        return 0;
}

void quicksort(int vetor[], int comeco, int fim , int mod){
    int i, j, pivo, aux;
    i = comeco;
    j = fim-1;
    pivo = vetor[(comeco + fim) / 2];
    while(i <= j)    {
        while(compara(vetor[i] , pivo , mod) && i < fim){
            i++;
        }
        while(compara(vetor[j] , pivo , mod) && j > comeco)     {
            j--;
        }
        if(i <= j)
        {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
        }
    }
    if(j > comeco)
        quicksort(vetor, comeco, j+1 , mod);
    if(i < fim)
        quicksort(vetor, i, fim , mod);
}

int main(){
    int n, m, i;    
	// cria o vetor com o tamanho máximo para as entradas.
    int vetor[10001];

	//leitura do n e m
    scanf("%d %d", &n, &m);
    
    while (n>0){
        for (i = 0; i < n; ++i)
			scanf("%d", &vetor[i]);
		
		//Aqui chama o algoritmo de ordenação adaptado para esse problema, 
		//   só precisam colocar a chamada da função aqui e implementar o algoritmo de ordenação.
		
		//mergeSort();
		quicksort(vetor, 0, n , m);
		
		
		//Imprime a resposta no formato esperado.
		printf("%d %d\n", n, m);
		for (i = 0; i < n; ++i)
			printf("%d\n", vetor[i]);
	    
		
		//leitura do n e m
	    scanf("%d %d", &n, &m);
    }
    
	//Imprime o último par de n e m, mesmo quando for zero.
    printf("%d %d\n", n, m);
    
    return 0;
}

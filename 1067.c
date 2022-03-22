#include <stdio.h>

void impares(int x , int n){
   if(n > x)
        return;
        
        
    printf("%d\n",n);
    impares(x, n+2);
   
}

int main()
{
    int entrada;
    
    scanf("%d", &entrada);
    
    impares(entrada,1);
    return 0;
}
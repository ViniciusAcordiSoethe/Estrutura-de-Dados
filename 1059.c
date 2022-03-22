#include <stdio.h>

void pares(int n){
   if(n % 2 == 0 && n <= 100){
       printf("%d\n",n);
       pares(n + 1);
   }else{
       pares(n + 1);
   }
}

int main()
{
    pares(2);

    return 0;
}
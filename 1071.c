#include <stdio.h>

int soma(int i ,int f){
    if(i >= f)
        return 0;
    if(i%2 != 0)
        return i + soma(i+1,f);
    else
        return soma(i+1,f);
}     


int main()
{
    int x, y;
    
    scanf("%d %d", &x, &y);
    
    int res;
    if(x>y){
        res = soma(y+1 , x);
    }else{
        res = soma(x+1,y);
    }

    printf("%d\n", res);
    return 0;
}
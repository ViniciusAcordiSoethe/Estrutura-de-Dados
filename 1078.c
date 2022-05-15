#include <stdio.h>

int tabuda(int i, int veilorReciver){
    if(i <= 10 ){
       int re = i * veilorReciver;
       printf("%d x %d = %d\n",i , veilorReciver , re);
       tabuda(i+1,veilorReciver);
    }else{
       return 0;
    }
}

int main()
{
    int i =1;
    int veilorReciver = 0;
    
    scanf("%d", &veilorReciver);
    tabuda(i,veilorReciver);
    
}

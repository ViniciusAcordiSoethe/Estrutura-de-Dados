#include <stdio.h>

void checaSenha(){
    int senhaRecebida;
    scanf("%d",&senhaRecebida);
    if(senhaRecebida == 2002){
        printf("Acesso Permitido\n");
        return ;
    }else{
        printf("Senha Invalida\n");
        checaSenha();
    }
}

int main()
{
    checaSenha();
}

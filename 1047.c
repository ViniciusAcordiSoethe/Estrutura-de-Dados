#include <stdio.h>

int main()
{
    int horaInicial = 0;
    int minutoInicial = 0;
    int horaFinal = 0;
    int minutoFinal = 0;
    
    scanf("%d %d %d %d", &horaInicial , &minutoInicial , &horaFinal , &minutoFinal);
    
    int converhrinicial ,  converhrfinal;
    
    converhrinicial = horaInicial * 60 + minutoInicial;
    converhrfinal = horaFinal * 60 + minutoFinal;
    
    int duracao;
    if( converhrinicial < converhrfinal){
        duracao = converhrfinal - converhrinicial;
    }else{
        duracao=(24*60 - converhrinicial) + converhrfinal;
    }    

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", duracao/60 , duracao%60);

    return 0;
}
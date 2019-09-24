#include <stdlib.h>
#include "tamagotchi.h"

//variáveis autoexplicativas, x sendo uma variável multiuso durante o jogo
int jogo = 1, tempo, tempoevolucao, tempogestacao, x, fome = 10, felicidade = 10, higiene = 10;
char nome[26], nome0[26], nivel = 64;

int main()
{
    //geração de números aleatórios
    srand(time(NULL));

    //obtém o nome, salva no ponteiro, copia o ponteiro para as auxiliares principais de funções main e display
    preenchervazio(strcpy(nome0, obternome()));

    //loop do jogo
    for (tempo = 1, tempoevolucao = 1, tempogestacao = 1; jogo != 0; tempo++, tempoevolucao++, tempogestacao++)
    {
        niveldomonstrinho();
        nascimento();
        display();
        interacaousuario();
        //condicoesaleatorias();
        jogo = fatalidades();

        //função de decorrência do tempo de do jogo,o total encontra-se no display
        //sleep(1);
    }
    //limpar a tela pós-jogo
    limpartela();
    return 0;
}
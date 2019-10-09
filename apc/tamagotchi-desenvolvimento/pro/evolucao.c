#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "tamagotchi.h"

int main()
{
    salvarNome();

    //for (tempo = 1, tempoevolucao = 1, tempogestacao = 1; jogo != 0; tempo++, tempoevolucao++, tempogestacao++)
    while (jogo)
    {
        niveldomonstrinho();
        nascimento();
        display();
        interacaousuario();
        condicoesaleatorias();
        jogo = fatalidades();
        tempoDeEspera(1);
    }
    limpartela();
    return 0;
}
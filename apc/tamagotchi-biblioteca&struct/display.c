#include <stdio.h>
#include <stdlib.h>
#define LINHAMAX 43
#define DEBUG(x) printf("%s", x);

char *tabulacao(int num, ...)
{
    char *tabulacao = malloc(1 + num * sizeof(char));
    for (int i = 0; i < num; i++)
    {
        tabulacao[i] = '\t';
    }
    return tabulacao;
}

char *linhaLimitadora()
{
    char *linhaLimitadora = malloc(LINHAMAX * sizeof(char));
    linhaLimitadora = "#########################################\n";
    return linhaLimitadora;
}

char *linhaNome()
{
    char *linhaNome = malloc(LINHAMAX * sizeof(char));
    linhaNome = "# Nome: s                               #\n";
    return linhaNome;
}

char* linhaTempoVida()
{
    char* linhaTempoVida = malloc(LINHAMAX * sizeof(char));
    linhaTempoVida = "# Tempo de Vida: d                      #\n";
    return linhaTempoVida;
}

int main()
{
    /*
        char linhaLimitadora[LINHAMAX] = "#########################################\n";
        char linhaNome[LINHAMAX]       = "# Nome: s                               #\n";
        char linhaTempoVida[LINHAMAX]  = "# Tempo de Vida: d                      #\n";
        char linhaFelicidade[LINHAMAX] = "# Felicidade: d                         #\n";
        char linhaHigiene[LINHAMAX]    = "# Higiene:    d                         #\n";
        char linhaFome[LINHAMAX]       = "# Fome:       d                         #\n";
        char linhaEspacadora[LINHAMAX] = "#                                       #\n";
        char linhaIdade[LINHAMAX]      = "#               s                       #\n";


        char* display[14] = {
            linhaLimitadora,
            linhaNome,
            linhaTempoVida,
            linhaEspacadora,
            linhaFelicidade,
            linhaHigiene,
            linhaFome,
            linhaEspacadora,
            linhaEspacadora,
            linhaIdade,
            linhaIdade,
            linhaEspacadora,
            linhaEspacadora,
            linhaLimitadora
            #########################################
            # Nome: s                               #
            # Tempo de Vida: d                      #
            #                                       #
            # Felicidade: d                         #
            # Higiene:    d                         #
            # Fome:       d                         #
            #                                       #
            #               s                       #
            #               s                       #
            #                                       #
            #########################################
        };

        for (int i = 0; i < 14; i++)
        {
            DEBUG(display[i]);
        }
    */

    DEBUG(linhaTempoVida());
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define LINHAMAX 43
#define DEBUG(x) printf("%s", x);

int main()
{
    // char *nome = "\
    //     #########################################\n\
    //     # Nome: %s                               #\n\
    //     # Tempo de Vida: %d                      #\n\
    //     # Felicidade: %d                         #\n\
    //     # Higiene:    %d                         #\n\
    //     # Fome:       %d                         #\n\
    //     #                                       #\n\
    //     #               %s%s                      #\n\
    //     #               %s%s                      #\n";
    char *nome = "# Nome: %s                               #\n";
    char *tempoDeVida = "# Tempo de Vida: %d                      #\n";
    // char *"# Felicidade: %d                         #\n";
    // char *"# Higiene:    %d                         #\n";
    // char *"# Fome:       %d                         #\n";
    // char *"#                                       #\n";
    // char *"#               %s%s                      #\n";
    // char *"#               %s%s                      #\n";

    char **stringFinal = {
        nome,
        tempoDeVida
    };

    printf(*stringFinal[0],"tamagotchi",10);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define LINHAMAX 43
#define DEBUG(x) printf("%s", x);

int main()
{
    char *nome = "\
        #########################################\n\
        # Nome: %s                               #\n\
        # Tempo de Vida: %d                      #\n\
        # Felicidade: %d                         #\n\
        # Higiene:    %d                         #\n\
        # Fome:       %d                         #\n\
        #                                       #\n\
        #               %s%s                      #\n\
        #               %s%s                      #\n";

    printf(nome,"nome",10,10,10,10,"a","a","a","a");
    return 0;
}
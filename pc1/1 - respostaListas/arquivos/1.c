#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[])
{
    FILE *arq[3];

    arq[0] = fopen(argv[2],"a");    
    for (int i = 1; i < 3; i++){
        arq[i] = fopen(argv[i + 2],"r");
    }

    for (int i = 0; i < 3; i ++){
        if (arq[i] == NULL){
            puts("erro ao abrir arquivo");
            exit(1);
        }
        puts("aberto com sucesso");
    }

    do
    {
        char c = 
        
    } while (c != EOF);
    





    return 0;
}

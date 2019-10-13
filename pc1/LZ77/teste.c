#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str[100];    // char para receber string
    scanf("%s", str); // recebimento da string

    char *ptr_str;                // ponteiro para função strtok
    ptr_str = strtok(str, "(,)"); // operação de iniciação de leitura da string

    char str_final[100]; // string decodificada

    for (int i = 1; ptr_str != NULL; i++)
    {
        // estrutura da tripla (x,y,c) -- sendo 'c' o char a ser colocado na string final
        int pri_parametro;  //  parametro 'x'
        int seg_parametro;  //  parametro 'y'


        if (i % 3 == 0 && i <= 3) // condição para iniciação da string com o primeiro pack da codificação
        {
            strcat(str_final, ptr_str);
        }
        else if (i % 3 == 1)
        {
            puts("mod 3 = 1");
            pri_parametro = atoi(ptr_str); // salvar o número da codificação
        }
        else if (i % 3 == 2)
        {
            puts("mod 3 = 2");
            seg_parametro = atoi(ptr_str); // salvar o número da codificação
        }
        else if (i % 3 == 0)
        {
        }

        printf("%s\n", ptr_str);
        ptr_str = strtok(NULL, "(,)"); // atualização do ponteiro
    }

    putchar('\n');
    puts(str_final);

    return 0;
}
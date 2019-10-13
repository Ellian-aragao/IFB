#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str[100];    // char para receber string
    scanf("%s", str); // recebimento da string

    char *substring;                // ponteiro para função strtok
    substring = strtok(str, "(,)"); // operação de iniciação de leitura da string

    char str_final[100]; // string decodificada
    int str_tam = 0;     // tamanho do str_final


    for (int i = 1; substring != NULL; i++)
    {
        // estrutura da tripla (x,y,c) -- sendo 'c' o char a ser colocado na string final
        int pri_parametro;  //  parâmetro 'x' -- quantidade de caracteres a voltar na string
        int seg_parametro;  //  parâmetro 'y' -- caracteres a serem concatenados


        if (i % 3 == 0 && i <= 3) // condição para iniciação da string com o primeiro pack da codificação
        {
            puts("primeira letra");
            strcat(str_final, substring); // add da primeira letra na string final
            str_tam++;                    // "strlen" manual
        }
        else if (i % 3 == 1)
        {
            // puts("mod 3 = 1");
            pri_parametro = atoi(substring); // salvar o número da codificação
        }
        else if (i % 3 == 2)
        {
            // puts("mod 3 = 2");
            seg_parametro = atoi(substring); // salvar o número da codificação
        }
        else if (i % 3 == 0 && i > 3)
        {
            puts("entrou na i \% 3 == 0 && i > 3 condição");

//ponto que parei            
            int diferenca = str_tam - pri_parametro;  // número que vai iniciar o ponto de cópia da string
            while ( seg_parametro > 0)                // cópia dos ciclos dentro do parâmetro 'y'
            {
                char *ptr_str;
                *ptr_str = str_final[diferenca]; // ponteiro apontado para início do ponto de cópia
                for (int j = 0; j < pri_parametro; j++) // cópia dos ciclos dentro do parâmetro 'x'
                {
                    strcat(str_final, ptr_str);
                }

                seg_parametro--;
            }

        }

        printf("%s\n", substring);
        substring = strtok(NULL, "(,)"); // atualização do ponteiro com a substring atual
    }

    putchar('\n');
    strcat(str_final,"\0");
    puts(str_final);

    return 0;
}
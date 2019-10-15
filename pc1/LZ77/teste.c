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
    int str_tam = 0;     // tamanho da str_final

    for (int i = 1; substring != NULL; i++)
    {
        // estrutura da tripla (x,y,c) -- sendo 'c' o char a ser colocado na string final
        int pri_parametro; //  parâmetro 'x' -- quantidade de caracteres a voltar na string
        int seg_parametro; //  parâmetro 'y' -- caracteres a serem concatenados

        if (i % 3 == 0 && i <= 3) // condição para iniciação da string com o primeiro pack da codificação
        {
            // printf("3º parametro = %s\n", substring);
            strcat(str_final, substring); // add da primeira letra na string final
            str_tam++;                    // "strlen" manual
        }
        else if (i % 3 == 1)
        {
            pri_parametro = atoi(substring); // salvar o número da codificação
            // printf("1º parametro = %d\n", pri_parametro);
        }
        else if (i % 3 == 2)
        {
            seg_parametro = atoi(substring); // salvar o número da codificação
            // printf("2º parametro = %d\n", seg_parametro);
        }
        else if (i % 3 == 0 && i > 3)
        {
            if (pri_parametro > 0)
            {
                char *ptr_str = malloc((pri_parametro) * sizeof(char)); // armazena o tamanho do parametro 'x'
                int diferenca = str_tam - pri_parametro;              // ponto de inicio para cópia

                for (int j = 0; j < pri_parametro; j++, diferenca++) // realiza a cópia dos caracteres do parametro 'x'
                {
                    ptr_str[j] = str_final[diferenca];
                }
                printf("copia ->%s\n", ptr_str);

                while (seg_parametro - pri_parametro >= 0)  // caso a string a ser copiada seja do tamanho que voltou
                {
                    strcat(str_final, ptr_str);
                    str_tam += seg_parametro;
                    seg_parametro -= pri_parametro;
                }

                for (int j = 0; j < seg_parametro; j++)  // caso ainda restam letras menores que o tamanho da string auxiliar, copia só estas letras
                {
                    str_final[str_tam] = ptr_str[j];
                    str_tam++;
                }
                free(ptr_str);

                // for (int j = 0; j < seg_parametro; j++)
                // {
                //     for (int t = 0; t < pri_parametro - 1; t++)
                //     {
                //         str_tam++;
                //         str_final[str_tam] = ptr_str[t];
                //         //concatenacao_lim(str_final, str_tam, ptr_str,seg_parametro);
                //     }
                // }
            }

            /*                              copia através do ponteiro que percorre a str_final                 */
            // if (seg_parametro > 0)
            // {
            //     int diferenca = str_tam - pri_parametro; // número que vai iniciar o ponto de cópia da string
            //     while (seg_parametro > 0)                // cópia dos ciclos dentro do parâmetro 'y'
            //     {
            //         char *ptr_str;
            //         ptr_str = &str_final[diferenca];            // ponteiro apontado para início do ponto de cópia
            //         for (int j = 0; j < pri_parametro - 1; j++) // cópia dos ciclos dentro do parâmetro 'x'
            //         {
            //             printf("ptr_str = %s", ptr_str);
            //             concatenacao(str_final, str_tam, ptr_str);
            //             str_tam++;
            //         }

            //         seg_parametro--;
            //     }
            // }

            printf("3º parametro = %s\n", substring);
            strcat(str_final, substring);
            str_tam++;
            puts(str_final);
            printf("str_tam %d\n",str_tam);
        }
        substring = strtok(NULL, "(,)"); // atualização do ponteiro com a substring atual
    }

    putchar('\n');
    //strcat(str_final, "\0");
    puts(str_final);
    puts("ababcbababaaaaaa\\0");

    return 0;
}

/*
(-1,0,a)(0,0,b)(2,2,c)(4,3,a)(2,2,a)(1,4,\0)
ababcbababaaaaaa\0
*/
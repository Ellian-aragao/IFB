#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lz77decode.h"
void decompress(char* str)
{
    // char *str_orig = str;
    // while (*str != '\\')
    // {
    //     str++;
    // }
    // // str = str_orig;
    // puts(str);
    // exit(0);

    char *substring;                // ponteiro para função strtok
    substring = strtok(str, "(,)"); // operação de iniciação de leitura da string

    char str_final[100000]; // string decodificada
    int str_tam = 0;        // tamanho da str_final

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
            if(substring[0] == '\\')
                puts("achei \\");

            // para quando não houver que repetir nada, apenas append a substring
            if (pri_parametro > 0)
            {

                char *ptr_str = malloc((pri_parametro) * sizeof(char)); // armazena o tamanho do parametro 'x'
                int diferenca = str_tam - pri_parametro;                // ponto de início para cópia da string
                
                // realiza a cópia dos caracteres do parametro 'x'
                for (int j = 0; j < pri_parametro; j++, diferenca++) ptr_str[j] = str_final[diferenca];


                /***********************************    debug string de cópia  ***************************************************/
                // printf("copia ->%s\n", ptr_str);


                // caso a string a ser copiada seja do tamanho que voltou, ou que tenha pedaços grandes
                while (seg_parametro % pri_parametro == 0 && seg_parametro - pri_parametro >= 0) 
                {
                    strcat(str_final, ptr_str);      // append a string quando o auxiliar e do tamanho a ser add
                    str_tam += seg_parametro;        // add do tamanho segundo o valor len do ptr_str --> segundo parâmetro
                    seg_parametro -= pri_parametro;  // redução do segundo parâmetro através do valor da copia --> primeiro parâmetro


                    /********************************   debugger de parametros por iteração *************************************/
                    // printf("%d primeiro = %d, segundo %d\n", str_tam, pri_parametro, seg_parametro);
                }
                
                // aux = parâmetro de seleção do caractere; j = cálculo do andamento repetitivo segundo segundo parametro
                int aux = 0, j = 0;
                // caso ainda restam letras menores que o tamanho da string auxiliar, copia só estas letras que faltam
                for (j = 0, aux = 0; j < seg_parametro; j++, aux++)
                {
                    if (aux >= pri_parametro) aux = 0; // critério cíclico do algorítmo de descompressão --> estouro len do ptr_str
                    str_final[str_tam] = ptr_str[aux]; // caractere em append
                    str_tam++;                         // acrecimo por caractere add em append

                    /********************************   debugger de parametros por iteração *****************************************/
                    // printf("aux = %c\n", ptr_str[aux]);  // qual caractere para append
                    // printf("%d primeiro = %d, segundo %d\n", str_tam, pri_parametro, seg_parametro);  // valores dos parametros e len
                }

                str_final[str_tam] = '\0'; // encerra para cópia funcionar-->não faço ideia do porque ter funcionado
                free(ptr_str);             // liberar vetor para próxima iteração
            }

            strcat(str_final, substring); // adicionando o último parâmetro passado
            str_tam++;                    // incluindo letra a contagem

            /*****************************************  debugger de resultados  ****************************************************/
            // printf("3 parametro = %s\n", substring);        // exibição do terceiro parametro
            // puts(str_final);                                // resultado obtido pela iteração
            // for (int j = 0; j < str_tam; j++) putchar('A'); // parametro comparativo da quantidade de caracteres segundo str_tam
            // printf("  str_tam %d\n", str_tam);              // exibição do tamanho da string final e da comparativa
        }

        substring = strtok(NULL, "(,)"); // atualização do ponteiro com a substring atual
    }

    puts(str_final); // impressão da descompressão
    // puts("ababcbababaaaaaa\0"); // realização dos comparativos da decodificação com string resultado
}
/*
(-1,0,a)(0,0,b)(2,2,c)(4,3,a)(2,2,a)(1,4,\0)
ababcbababaaaaaa\0
*/

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
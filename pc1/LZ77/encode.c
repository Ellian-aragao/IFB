#include <stdio.h>
#include <string.h>
void compress(char *str, int k)
{

    int str_tam = 0;                   // contador com o tamanho da string
    printf("(-1,0,%c)", str[str_tam]); // primeiro parâmetro da codificação
    str_tam++;
    while (str[str_tam] != '\0')
    {
        for (int i = 0; i <= k && str_tam - i >= 0; i++)
        {
            
        }
    }
}

int main()
{
    char str[100]; // string a ser capturada para codificação
    int k;         // janela de entrada do programa
    scanf("%s %d", str, &k);
    compress(str, k);
    return 0;
}
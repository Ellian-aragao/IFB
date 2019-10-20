#include <stdio.h>
#include "funcoes.h"
#define TRUE 1
#define FALSE 0
int main()
{
    int parametro = TRUE;
    limpartela();
    while (parametro)
    {
        puts("Digite qual opção deseja testar");
        puts("1 - epsilon da maquina");
        puts("2 - Taylor");
        puts("3 - bisseccao");
        puts("4 - limpar tela");
        puts("0 - sair");
        putchar('\n');
        int opcao;
        scanf("%d",&opcao);
        switch (opcao)
        {
            case 1:
                epsilon();
                break;
            
            case 2:
                taylor();
                break;
            
            case 3:
                bisseccao();
                break;

            case 4:
                limpartela();
                break;
            
            case 0:
                parametro = FALSE;
                break;

            default:
                printf("opcao invalida\n\n");
                break;
        }
	printf("\n\n");
    }
    return 0;
}

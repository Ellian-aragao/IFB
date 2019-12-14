#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "tamagotchi.h"

//obtém o nome, salva no ponteiro, copia o ponteiro para as auxiliares principais de funções main e display
void salvarNome()
{
    preenchervazio(strcpy(, obternome()));
}

//obtém o nome a ser usado no jogo
char *obternome(void)
{
    int boleano = 1;
    limpartela();
    while (boleano == 1)
    {
        espacos(1);
        puts("digite um nome para o monstrinho ASCII, de até 25 caracteres");
        scanf("%[^\n]s", nome);
        setbuf(stdin,NULL);
        if (strlen(nome) > 25)
        {
            espacos(4);
            puts("TENTE NOVAMENTE");
            hashtag(79);
            espacos(0);
        }
        else
        {
            boleano = 0;
        }
    }

    return nome;
}

//prenche o espaço vazio da string auxiliar para função display com ' '
void preenchervazio(char *nome)
{
    if (strlen(nome) < 25)
    {
        for (x = strlen(nome); x < 25; x++)
        {
            nome0[x] = ' ';
        }
        nome0[x] = '\0';
    }
}



//função para iniciação do tamagotchi a vida emfim
void nascimento()
{
    //controlador da mudança de nível de gestação para operante
    if (tempogestacao == 10)
    {
        limpartela();
        espacos(3);
        printf("%s nasceu\n", nome);
        sleep(2);
        tempo = 1;
        nivel++;
    }
}

//loop de interação maquina-usuário
void interacaousuario()
{
    if (tempo % 10 == 0 && tempogestacao > 9)
    {
        puts("(1) comida  (2) carinho  (3) banho  (4) ...");
        espacos(3);
        puts("digite uma opcao...");
        scanf("%d", &x);
        switch (x)
        {
            //alimentar o monstrinho
            case 1:
            {
                limpartela();
                espacos(3);
                printf("%s, hora de comer!\n", nome);
                sleep(2);
                espacos(3);
                printf("humm, que delicia mestre!\n");
                sleep(1);
                fome = fome - 2;
                higiene = higiene - 2;
                break;
            }

            //dar atenção ao monstrinho
            case 2:
            {
                limpartela();
                espacos(3);
                puts("o carinho do mestre me faz bem :)");
                sleep(1);
                felicidade = felicidade + 3;
                fome = fome + 1;
                break;
            }

            //higienizar o monstrinho
            case 3:
            {
                limpartela();
                espacos(3);
                printf("%s, hora do banho!\n", nome);
                sleep(2);
                espacos(3);
                puts("Naooooooooooooooooo...");
                sleep(1);
                higiene = higiene + 7;
                felicidade = felicidade - 4;
                break;
            }

            //fazer absolutamente nada
            case 4:
            {
                break;
            }

            //padrão fora das alternativas
            default:
            {
                limpartela();
                espacos(3);
                puts("O que foi isso mestre? O que queria de mim?");
                sleep(2);
                felicidade = felicidade - 5;
            }
        }
    }
}

//condições aleatórias
void condicoesaleatorias()
{
    if ( tempo % 5 == 0 && tempogestacao > 9 )
    {
        // geração de números aleatórios
        srand(time(NULL));

        // gerador de números aleatórios que vão configurar algum problema a ser sofrido pelo monstrinho 
        x = rand() % 3;
        switch (x)
        {
            // incrementar fome
            case 0:
            {
                fome++;
                break;
            }

            // decrementar felicidade
            case 1:
            {
                felicidade--;
                break;
            }

            // decrementar higiene
            case 2:
            {
                higiene--;
                break;
            }
        }
    }
}

//verificador fatalidades possíveis
int fatalidades(Tamagotchi *tamagotchi)
{
    //fome chega a 15 - máximo
    if (tamagotchi->fome >= 15)
    {
        limpartela();
        espacos(3);
        printf("%s morreu de fome! :(\n", tamagotchi->nome);
        sleep(3);
        
    }

    //fome chega a 0 - mínimo
    if (tamagotchi->fome <= 0)
    {
        limpartela();
        espacos(3);
        printf("%s morreu de bucho cheio!\n", tamagotchi->nome);
        sleep(3);
        
    }

    //felicidade chegou a 0 - mínimo
    if (tamagotchi->felicidade <= 0)
    {
        limpartela();
        espacos(3);
        printf("%s morreu de desgosto\n", tamagotchi->nome);
        sleep(3);
        
    }

    //felicidade chega a 15 - máximo
    if (tamagotchi->felicidade >= 15)
    {
        limpartela();
        espacos(3);
        printf("%s morreu de rir :D ops... :(\n", tamagotchi->nome);
        sleep(3);
        
    }

    //higiene chega a 0 - mínimo
    if (tamagotchi->higiene <= 0)
    {
        limpartela();
        espacos(3);
        printf("%s morreu de doença infecciosa!\n", tamagotchi->nome);
        sleep(3);
        
    }

    //higiene chega a 15 - máximo
    if (tamagotchi->higiene >= 15)
    {
        limpartela();
        espacos(3);
        printf("%s morreu por falta de anticorpos!\n", tamagotchi->nome);
        sleep(3);
        
    }
    //verificar se chegou a nível máximo do jogo
    if (tamagotchi->nivel == 90)
    {
        limpartela();
        espacos(3);
        printf("%s teve uma bela vida...\n", tamagotchi->nome);
        sleep(3);
        
    }
    return 1;
}

//operador de nível do monstrinho
void niveldomonstrinho()
{
    if (tempoevolucao == nivel)
    {
        nivel++;
        jogo = fatalidades(jogo);
        tempoevolucao = 0;
        if (jogo != 0)
        {
            limpartela();
            espacos(3);
            printf("parabens, '%s' evoluiu\n", nome);
            sleep(2);
        }
    }
}

//função para limpeza da tela
void limpartela()
{
    system("clear");
}

// marcar decorrência de tempo
void tempoDeEspera(int segundos)
{
    sleep(segundos);
}

//função para o display, gerador da linha superior e inferior
void hashtag(int num)
{
    int i;
    for (i = 0; i <= num; i++)
    {
        printf("#");
    }
}

//função para o display, pular linha e espaçamento
void espacos(int num)
{
    int i;
    putchar('\n');
    for (i = 0; i < num; i++)
    {
        printf("\t");
    }
}

// execulta a rotina do jogo
void tamagotchiGame()
{
    struct Tamagotchi tamagotchi;
    salvarNome();
    while (tamagotchi.status)
    {
        niveldomonstrinho();
        nascimento();
        display();
        interacaousuario();
        condicoesaleatorias();
        tamagotchi.status = fatalidades();
        tempoDeEspera(1);
    }
    limpartela();
}

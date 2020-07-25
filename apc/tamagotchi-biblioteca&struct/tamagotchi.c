#include "tamagotchi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// salva o nome do tamagotchi
void gravaNome(Tamagotchi *tamagotchi)
{
    printf("digite um nome para o monstrinho: ");
    scanf("%[^\n]s", tamagotchi->nome);
    gravaNomeDisplay(tamagotchi);
}

// salva nome para exibir no display
void gravaNomeDisplay(Tamagotchi *tamagotchi)
{
    strcpy(tamagotchi->nomeDisplay, tamagotchi->nome);
    int i, tam = strlen(tamagotchi->nomeDisplay);
    for (i = tam; i < 31; i++)
    {
        tamagotchi->nomeDisplay[i] = ' ';
    }
    tamagotchi->nomeDisplay[i] = '\0';
}

//imagem de interação com o usuário e animação pós-nascimento
void display(Tamagotchi *tamagotchi)
{
    //condição para quando esta a nascer o monstrinho
    if (tamagotchi->tempogestacao < 10)
    {
        limpartela();
        espacos(3);
        hashtag(40);
        espacos(3);
        hashtag(0);
        printf(" nome: %s #", tamagotchi->nomeDisplay);
        espacos(3);
        hashtag(0);
        printf(" tempo de vida: %d segundos\t\t#", tamagotchi->tempo);
        espacos(3);
        hashtag(0);
        printf(" fome: %d,", tamagotchi->fome);
        printf("felicidade: %d,", tamagotchi->felicidade);
        printf("higiene: %d", tamagotchi->higiene);
        printf("\t#");
        espacos(3);
        hashtag(0);
        printf("\t\t\t\t\t#");
        espacos(3);
        hashtag(0);
        printf("\t\t %c%c\t\t\t#", tamagotchi->nivel, tamagotchi->nivel);
        espacos(3);
        hashtag(0);
        printf("\t\t %c%c\t\t\t#", tamagotchi->nivel, tamagotchi->nivel);
        espacos(3);
        hashtag(40);
        espacos(3);
    }

    //animação do monstrinho quando operante
    else
    {
        if (tamagotchi->tempo % 2 == 0)
        {
            limpartela();
            espacos(3);
            hashtag(40);
            espacos(3);
            hashtag(0);
            printf(" nome: %s \t#", tamagotchi->nomeDisplay);
            espacos(3);
            hashtag(0);
            printf(" tempo de vida: %d segundos\t\t#", tamagotchi->tempo);
            espacos(3);
            hashtag(0);
            printf(" fome: %d,", tamagotchi->fome);
            printf("felicidade: %d,", tamagotchi->felicidade);
            printf("higiene: %d", tamagotchi->higiene);
            printf("\t#");
            espacos(3);
            hashtag(0);
            printf("\t\t\t\t\t#");
            espacos(3);
            hashtag(0);
            printf("\t\t%c%c\t\t\t#", tamagotchi->nivel, tamagotchi->nivel);
            espacos(3);
            hashtag(0);
            printf("\t\t%c%c\t\t\t#", tamagotchi->nivel, tamagotchi->nivel);
            espacos(3);
            hashtag(40);
            espacos(3);
        }
        else
        {
            limpartela();
            espacos(3);
            hashtag(40);
            espacos(3);
            hashtag(0);
            printf(" nome: %s \t#", tamagotchi->nomeDisplay);
            espacos(3);
            hashtag(0);
            printf(" tempo de vida: %d segundos\t\t#", tamagotchi->tempo);
            espacos(3);
            hashtag(0);
            printf(" fome: %d,", tamagotchi->fome);
            printf("felicidade: %d,", tamagotchi->felicidade);
            printf("higiene: %d", tamagotchi->higiene);
            printf("\t#");
            espacos(3);
            hashtag(0);
            printf("\t\t\t\t\t#");
            espacos(3);
            hashtag(0);
            printf("\t\t %c%c\t\t\t#", tamagotchi->nivel, tamagotchi->nivel);
            espacos(3);
            hashtag(0);
            printf("\t\t %c%c\t\t\t#", tamagotchi->nivel, tamagotchi->nivel);
            espacos(3);
            hashtag(40);
            espacos(3);
        }
    }
}

//função para iniciação do tamagotchi a vida emfim
void nascimento(Tamagotchi *tamagotchi)
{
    //controlador da mudança de nível de gestação para operante
    if (tamagotchi->tempogestacao == 10)
    {
        limpartela();
        espacos(3);
        printf("%s nasceu\n", tamagotchi->nome);
        sleep(2);
        tamagotchi->tempo = 1;
        tamagotchi->nivel++;
    }
}

//loop de interação maquina-usuário
void interacaousuario(Tamagotchi *tamagotchi)
{
    if (tamagotchi->tempo % 10 == 0 && tamagotchi->tempogestacao > 9)
    {
        puts("(1) comida  (2) carinho  (3) banho  (4) ...");
        espacos(3);
        puts("digite uma opcao...");
        int x;
        scanf("%d", &x);
        switch (x)
        {
        //alimentar o monstrinho
        case 1:
        {
            limpartela();
            espacos(3);
            printf("%s, hora de comer!\n", tamagotchi->nome);
            sleep(2);
            espacos(3);
            printf("humm, que delicia mestre!\n");
            sleep(1);
            tamagotchi->fome -= 2;
            tamagotchi->higiene -= 2;
            break;
        }

        //dar atenção ao monstrinho
        case 2:
        {
            limpartela();
            espacos(3);
            puts("o carinho do mestre me faz bem :)");
            sleep(1);
            tamagotchi->felicidade += 3;
            tamagotchi->fome += 1;
            break;
        }

        //higienizar o monstrinho
        case 3:
        {
            limpartela();
            espacos(3);
            printf("%s, hora do banho!\n", tamagotchi->nome);
            sleep(2);
            espacos(3);
            puts("Naooooooooooooooooo...");
            sleep(1);
            tamagotchi->higiene += 7;
            tamagotchi->felicidade -= 4;
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
            tamagotchi->felicidade -= 5;
        }
        }
    }
}

//condições aleatórias
void condicoesaleatorias(Tamagotchi *tamagotchi)
{
    if (tamagotchi->tempo % 5 == 0 && tamagotchi->tempogestacao > 9)
    {
        // geração de números aleatórios
        srand(time(NULL));

        // gerador de números aleatórios que vão configurar algum problema a ser sofrido pelo monstrinho
        int x = rand() % 3;
        switch (x)
        {
        // incrementar fome
        case 0:
        {
            tamagotchi->fome++;
            break;
        }

        // decrementar felicidade
        case 1:
        {
            tamagotchi->felicidade--;
            break;
        }

        // decrementar higiene
        case 2:
        {
            tamagotchi->higiene--;
            break;
        }
        }
    }
}

//verificador fatalidades possíveis
void fatalidades(Tamagotchi *tamagotchi)
{
    //fome chega a 15 - máximo
    if (tamagotchi->fome >= 15)
    {
        limpartela();
        espacos(3);
        printf("%s morreu de fome! :(\n", tamagotchi->nome);
        sleep(3);
        tamagotchi->status = FALSE;
    }

    //fome chega a 0 - mínimo
    if (tamagotchi->fome <= 0)
    {
        limpartela();
        espacos(3);
        printf("%s morreu de bucho cheio!\n", tamagotchi->nome);
        sleep(3);
        tamagotchi->status = FALSE;
    }

    //felicidade chegou a 0 - mínimo
    if (tamagotchi->felicidade <= 0)
    {
        limpartela();
        espacos(3);
        printf("%s morreu de desgosto\n", tamagotchi->nome);
        sleep(3);
        tamagotchi->status = FALSE;
    }

    //felicidade chega a 15 - máximo
    if (tamagotchi->felicidade >= 15)
    {
        limpartela();
        espacos(3);
        printf("%s morreu de rir :D ops... :(\n", tamagotchi->nome);
        sleep(3);
        tamagotchi->status = FALSE;
    }

    //higiene chega a 0 - mínimo
    if (tamagotchi->higiene <= 0)
    {
        limpartela();
        espacos(3);
        printf("%s morreu de doença infecciosa!\n", tamagotchi->nome);
        sleep(3);
        tamagotchi->status = FALSE;
    }

    //higiene chega a 15 - máximo
    if (tamagotchi->higiene >= 15)
    {
        limpartela();
        espacos(3);
        printf("%s morreu por falta de anticorpos!\n", tamagotchi->nome);
        sleep(3);
        tamagotchi->status = FALSE;
    }
    //verificar se chegou a nível máximo do jogo
    if (tamagotchi->nivel == 90)
    {
        limpartela();
        espacos(3);
        printf("%s teve uma bela vida...\n", tamagotchi->nome);
        sleep(3);
        tamagotchi->status = FALSE;
    }
}
//operador de nível do monstrinho
void niveldomonstrinho(Tamagotchi *tamagotchi)
{
    if (tamagotchi->tempoevolucao == tamagotchi->nivel)
    {
        tamagotchi->nivel++;
        fatalidades(tamagotchi);
        tamagotchi->tempoevolucao = 0;
        if (tamagotchi->status != 0)
        {
            limpartela();
            espacos(3);
            printf("parabens, '%s' evoluiu\n", tamagotchi->nome);
            sleep(2);
        }
    }
}

//função para limpeza da tela
void limpartela(void)
{
    system("clear");
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

// inicia as variáveis do tamagotchi
void construtorTamagotchi(Tamagotchi *tamagotchi)
{
    tamagotchi->felicidade = 10;
    tamagotchi->fome = 10;
    tamagotchi->higiene = 10;
    tamagotchi->tempo = 0;
    tamagotchi->tempoevolucao = 0;
    tamagotchi->tempogestacao = 0;
    tamagotchi->nivel = '@';
    tamagotchi->status = TRUE;
}

// faz a contagem do tempo do tamagotchi
void countTamagotchi(Tamagotchi *tamagotchi)
{
    tamagotchi->tempo++;
    tamagotchi->tempoevolucao++;
    tamagotchi->tempogestacao++;
}

// execulta a rotina do jogo
void initTamagotchiGame(void)
{
    Tamagotchi tamagotchi;
    gravaNome(&tamagotchi);
    construtorTamagotchi(&tamagotchi);

    while (tamagotchi.status)
    {
        niveldomonstrinho(&tamagotchi);
        nascimento(&tamagotchi);
        display(&tamagotchi);
        interacaousuario(&tamagotchi);
        condicoesaleatorias(&tamagotchi);
        fatalidades(&tamagotchi);
        countTamagotchi(&tamagotchi);
        sleep(1);
    }
    limpartela();
}
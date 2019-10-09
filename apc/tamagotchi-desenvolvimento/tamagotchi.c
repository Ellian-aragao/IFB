#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

//variáveis autoexplicativas, x sendo uma variável multiuso durante o jogo
int jogo = 1, tempo, tempoevolucao, tempogestacao, x, fome = 10, felicidade = 10, higiene = 10;
char nome[26], nome0[26], nivel = 64;

//função para limpeza da tela
void limpartela()
{
    system("clear");
}

//função para o dysplay, gerador da linha superior e inferior
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
        getchar();
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

//imagem de interação com o usuário e animação pós-nascimento
void display()
{
    //condição para quando esta a nascer o monstrinho
    if (tempogestacao < 10)
    {
        limpartela();
        espacos(3);
        hashtag(40);
        espacos(3);
        hashtag(0);
        printf(" nome: %s \t#", nome0);
        espacos(3);
        hashtag(0);
        printf(" tempo de vida: %d segundos\t\t#", tempo);
        espacos(3);
        hashtag(0);
        printf(" fome: %d,", fome);
        printf("felicidade: %d,", felicidade);
        printf("higiene: %d", higiene);
        printf("\t#");
        espacos(3);
        hashtag(0);
        printf("\t\t\t\t\t#");
        espacos(3);
        hashtag(0);
        printf("\t\t %c%c\t\t\t#", nivel, nivel);
        espacos(3);
        hashtag(0);
        printf("\t\t %c%c\t\t\t#", nivel, nivel);
        espacos(3);
        hashtag(40);
        espacos(3);
    }

    //animação do monstrinho quando operante
    else
    {
        if (tempo % 2 == 0)
        {
            limpartela();
            espacos(3);
            hashtag(40);
            espacos(3);
            hashtag(0);
            printf(" nome: %s \t#", nome0);
            espacos(3);
            hashtag(0);
            printf(" tempo de vida: %d segundos\t\t#", tempo);
            espacos(3);
            hashtag(0);
            printf(" fome: %d,", fome);
            printf("felicidade: %d,", felicidade);
            printf("higiene: %d", higiene);
            printf("\t#");
            espacos(3);
            hashtag(0);
            printf("\t\t\t\t\t#");
            espacos(3);
            hashtag(0);
            printf("\t\t%c%c\t\t\t#", nivel, nivel);
            espacos(3);
            hashtag(0);
            printf("\t\t%c%c\t\t\t#", nivel, nivel);
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
            printf(" nome: %s \t#", nome0);
            espacos(3);
            hashtag(0);
            printf(" tempo de vida: %d segundos\t\t#", tempo);
            espacos(3);
            hashtag(0);
            printf(" fome: %d,", fome);
            printf("felicidade: %d,", felicidade);
            printf("higiene: %d", higiene);
            printf("\t#");
            espacos(3);
            hashtag(0);
            printf("\t\t\t\t\t#");
            espacos(3);
            hashtag(0);
            printf("\t\t %c%c\t\t\t#", nivel, nivel);
            espacos(3);
            hashtag(0);
            printf("\t\t %c%c\t\t\t#", nivel, nivel);
            espacos(3);
            hashtag(40);
            espacos(3);
        }
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
/*
//condições aleatórias
int condicoesaleatorias()
{
    if ( tempo % 5 == 0 && tempogestacao > 9 )
    {
        //gerador de números aleatórios que vão configurar algum problema a ser sofrido pelo monstrinho 
        x = rand() % 3;
        switch (x)
        {

            //incrementar fome
            case 0:
            {
                fome++;
                break;
            }

            //decrementar felicidade
            case 1:
            {
                felicidade--;
                break;
            }

            //decrementar higiene
            case 2:
            {
                higiene--;
                break;
            }
            default:
            {
                break;
            }
        }
    }
}
*/

//verificador fatalidades possíveis
int fatalidades() // necessita do inteiro para terminar o jogo
{
    //fome chega a 15 - máximo
    if (fome >= 15)
    {
        limpartela();
        espacos(3);
        printf("%s morreu de fome! :(\n", nome);
        sleep(3);
        jogo = 0;
        return jogo;
    }

    //fome chega a 0 - mínimo
    if (fome <= 0)
    {
        limpartela();
        espacos(3);
        printf("%s morreu de bucho cheio!\n", nome);
        sleep(3);
        jogo = 0;
        return jogo;
    }

    //felicidade chegou a 0 - mínimo
    if (felicidade <= 0)
    {
        limpartela();
        espacos(3);
        printf("%s morreu de desgosto\n", nome);
        sleep(3);
        jogo = 0;
        return jogo;
    }

    //felicidade chega a 15 - máximo
    if (felicidade >= 15)
    {
        limpartela();
        espacos(3);
        printf("%s morreu de rir :D ops... :(\n", nome);
        sleep(3);
        jogo = 0;
        return jogo;
    }

    //higiene chega a 0 - mínimo
    if (higiene <= 0)
    {
        limpartela();
        espacos(3);
        printf("%s morreu de doença infecciosa!\n", nome);
        sleep(3);
        jogo = 0;
        return jogo;
    }

    //higiene chega a 15 - máximo
    if (higiene >= 15)
    {
        limpartela();
        espacos(3);
        printf("%s morreu por falta de anticorpos!\n", nome);
        sleep(3);
        jogo = 0;
        return jogo;
    }
    //verificar se chegou a nível máximo do jogo
    if (nivel == 90)
    {
        limpartela();
        espacos(3);
        printf("%s teve uma bela vida...\n", nome);
        sleep(3);
        jogo = 0;
        return jogo;
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

int main()
{
    //geração de números aleatórios
    srand(time(NULL));

    //obtém o nome, salva no ponteiro, copia o ponteiro para as auxiliares principais de funções main e display
    preenchervazio(strcpy(nome0, obternome()));

    //loop do jogo
    for (tempo = 1, tempoevolucao = 1, tempogestacao = 1; jogo != 0; tempo++, tempoevolucao++, tempogestacao++)
    {
        niveldomonstrinho();
        nascimento();
        display();
        interacaousuario();
        //condicoesaleatorias();
        jogo = fatalidades();

        //função de decorrência do tempo de do jogo,o total encontra-se no display
        //sleep(1);
    }
    //limpar a tela pós-jogo
    limpartela();
    return 0;
}
#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

//obtém o nome do do monstrinho
void name(char *nome)
{
    limpartela();
    espacos(3);
    puts("digite um nome para o monstrinho ASCII, de até 25 caracteres");
    scanf("%25[^\n]s",nome);
    getchar();
}

//função para limpeza da tela
void limpartela()
{
    system("clear");
}

//função para o display, gerador da linha superior e inferior
void hashtag(int num)
{
    int i;
    for ( i = 0; i <= num; i++)
    {
        putchar('#');
    } 
}

//função para o display, pular linha e espaçamento
void espacos(int num)
{
    int i;
    putchar('\n');
    for ( i = 0; i < num; i++)
    {    
        printf("\t");
    }
}

//função de exibição de tela interativa
void display(char *nome0,int tempo,int fome,int felicidade,int higiene,char nivel)
{
    limpartela();
    espacos(3);
    hashtag(40);
    espacos(3);
    hashtag(0);
    printf(" nome: %s \t#",nome0);
    espacos(3);
    hashtag(0);
    printf(" tempo de vida: %d segundos\t\t#",tempo);
    espacos(3);
    hashtag(0);
    printf(" fome: %d,",fome);
    printf("felicidade: %d,",felicidade);
    printf("higiene: %d",higiene);
    printf("\t#");
    espacos(3);
    hashtag(0);
    printf("\t\t\t\t\t#");
    espacos(3);
    hashtag(0);
    printf("\t\t%c%c\t\t\t#",nivel,nivel);
    espacos(3);
    hashtag(0);
    printf("\t\t%c%c\t\t\t#",nivel,nivel);
    espacos(3);
    hashtag(40);
    espacos(3);
}

int main(void)
{

    //variáveis autoexplicativas, x sendo uma variável multiuso durante o jogo
    int tempo,tempoevolucao,tempogestacao,x,fome=10,felicidade=10,higiene=10;
    // struct tamagotchi
    // {
    //     int tempo,tempoevolucao,tempogestacao,x,fome,higiene,felicidade;
    //     int time,gest_time,hungry,happy;
    //     char name[25], level;
    // };
    
    char nome[25],nome0[25],nivel=64;

    //geração de números aleatórios
    srand(time(NULL));

    //obtém o nome do do monstrinho
    //name(tamagotchi);


    //prenche o espaço vazio da string com ' '
    strcpy(nome0,nome);
    if ( strlen(nome) <= 25 )
    {
        for ( x = strlen(nome); x < 25; x++)
        {
            nome0[x] = ' ';
        }
        nome0[x] = '\0';
    }


    //loop do jogo
    for ( tempo = 1, tempoevolucao = 1,tempogestacao=1; tempo <= 1848; tempo++, tempoevolucao++, tempogestacao++)

    /* a condição do loop for é pautada no cálculo que obteve o tempo máximo do jogo, este fora obtido através da média aritmética do menor e maior
    nível que o tamagotchi poderia ter sendo multiplicado a quantidade de níveis que este pode passar, sendo assim possível uma taxa de erro */
    {

        //operador de nível do monstrinho
        if ( tempoevolucao == nivel )
        {
            nivel++;
            tempoevolucao=0;

            //verificar se chegou a nível máximo do jogo
            if (nivel >= 90 )
            {
                limpartela();
                espacos(3);
                printf("%s teve uma bela vida...\n",nome);
                sleep(5);
                break;
            }
            
            limpartela();
            espacos(3);
            printf("parabens, '%s' evoluiu\n",nome);
            sleep(2);
        }


        //função de tela para jogador
        display(nome0,tempo,fome,felicidade,higiene,nivel);


        //controlador da mudança de nível de gestação para operante
        if (tempogestacao == 10)
        {
            limpartela();
            espacos(3);
            printf("%s nasceu\n",nome);
            sleep(2);
            tempo=1;
            nivel++;
        }
        

        //loop de interação maquina-usuário
        if ( tempo % 10 == 0 && tempogestacao > 9)
        {
            puts("(1) comida  (2) carinho  (3) banho  (4) ...");
            espacos(3);
            puts("digite uma opcao...");
            scanf("%d",&x);
            switch (x)
            {
                /* loop interacional pautado em limpar a tela, exibir a mensagem, esperar, "possível ação a mais", decrementação ou incrementação */

                //alimentar o monstrinho
                case 1:
                {
                    limpartela();
                    espacos(3);
                    printf("%s, hora de comer!\n",nome);
                    sleep(2);
                    espacos(3);
                    printf("humm, que delicia mestre!\n");
                    sleep(1);
                    fome=fome-2;
                    higiene=higiene-2;
                    break;
                }

                //dar atenção ao monstrinho
                case 2:
                {
                    limpartela();
                    espacos(3);
                    puts("o carinho do mestre me faz bem :)");
                    sleep(1);
                    felicidade=felicidade+3;
                    fome=fome+1;
                    break;
                }

                //higienizar o monstrinho
                case 3:
                {
                    limpartela();
                    espacos(3);
                    printf("%s, hora do banho!\n",nome);
                    sleep(2);
                    espacos(3);
                    puts("Naooooooooooooooooo...");
                    sleep(1);
                    higiene=higiene+7;
                    felicidade=felicidade-4;
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
                    felicidade=felicidade-5;
                }
            }
        }

        //condições aleatórias
        if ( tempo % 5 == 0 && tempogestacao > 9 )

        /* gerador de números aleatórios que vão configurar algum problema a ser atendido do monstrinho */

        {
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
                    break;
            }

        }

        //verificador fatalidades possíveis
        if (1)

        /*aqui estão todas as fatalidades, exceto quando chega ao level máximo,
        esta se encontra junto com o sistema para upar de nível no início do loop.*/

        /* os verificadores de fatalidade são pautados em verificar a variável e então execultar a série de atividadas,
        estas vão pautar-se em limpar a tela, exibir a mensagem pré-definida, esperar 5 seg e então parar o loop principal */

        {
            //fome chega a 15 - máximo
            if (fome >= 15)
            {
                limpartela();
                espacos(3);
                printf("%s morreu de fome! :(\n",nome);
                sleep(5);
                break;
            }

            //fome chega a 0 - mínimo
            if (fome <= 0)
            {
                limpartela();
                espacos(3);
                printf("%s morreu de bucho cheio!\n",nome);
                sleep(5);
                break;
            }

            //felicidade chegou a 0 - mínimo
            if (felicidade <= 0)
            {
                limpartela();
                espacos(3);
                printf("%s morreu de desgosto\n",nome);
                sleep(5);
                break;
            }

            //felicidade chega a 15 - máximo
            if (felicidade >= 15)
            {
                limpartela();
                espacos(3);
                printf("%s morreu de rir :D ops... :(\n",nome);
                sleep(5);
                break;
            }

            //higiene chega a 0 - mínimo
            if (higiene <= 0)
            {
                limpartela();
                espacos(3);
                printf("%s morreu de doença infecciosa!\n",nome);
                sleep(5);
                break;
            }

            //higiene chega a 15 - máximo
            if (higiene >= 15)
            {
                limpartela();
                espacos(3);
                printf("%s morreu por falta de anticorpos!\n",nome);
                sleep(5);
                break;
            }
        }
        
        //função de decorrência do tempo do jogo, encontra-se no display
        sleep(1);
    }
    //limpar a tela pós-jogo
    limpartela();
    return 0;
}
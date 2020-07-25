#ifndef TAMAGOTCH_H
#define TAMAGOTCH_H
#define TRUE  1
#define FALSE 0

typedef struct Tamagotchi {
    char nome[26];
    char nomeDisplay [33];
    char nivel;
    int status;
    int tempo;
    int tempoevolucao;
    int tempogestacao;
    int fome;
    int felicidade;
    int higiene;
} Tamagotchi;

// executa a rotina do jogo
void initTamagotchiGame(void);
// função para limpeza da tela
void limpartela(void);
// marcar decorrência de tempo
void tempoDeEspera(int segundos);
// função para o display, gerador da linha superior e inferior
void hashtag(int num);
// função para o display, pular linha e espaçamento
void espacos(int num);
// imagem de interação com o usuário e animação pós-nascimento
void display(Tamagotchi *tamagotchi);
// função para iniciação do tamagotchi a vida emfim
void nascimento(Tamagotchi *tamagotchi);
// loop de interação maquina-usuário
void interacaousuario(Tamagotchi *tamagotchi);
// condições aleatórias
void condicoesaleatorias(Tamagotchi *tamagotchi);
// verificador fatalidades possíveis
void fatalidades(Tamagotchi *tamagotchi);
// operador de nível do monstrinho
void niveldomonstrinho(Tamagotchi *tamagotchi);
// salva o nome do tamagotchi
void gravaNome(Tamagotchi *tamagotchi);
// inicia as variáveis do tamagotchi
void construtorTamagotchi(Tamagotchi *tamagotchi);
// faz a contagem do tempo do tamagotchi
void countTamagotchi(Tamagotchi *tamagotchi);
// salva nome para exibir no display
void gravaNomeDisplay(Tamagotchi *tamagotchi);

#endif

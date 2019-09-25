#ifndef TAMAGOTCH_H
#define TAMAGOTCH_H

int jogo = 1, tempo, tempoevolucao, tempogestacao, x, fome = 10, felicidade = 10, higiene = 10;
char nome[26], nome0[26], nivel = 64;
struct tamagotchi
{
    char nome[26];
    int tempo;
    int tempoevolucao;
    int tempogestacao;
    int fome;
    int felicidade;
    int higiene;
};

//função para limpeza da tela
void limpartela();
// marcar decorrência de tempo
void tempoDeEspera(int segundos);
//função para o dysplay, gerador da linha superior e inferior
void hashtag(int num);
//função para o display, pular linha e espaçamento
void espacos(int num);
//obtém o nome a ser usado no jogo
char *obternome(void);
//prenche o espaço vazio da string auxiliar para função display com ' '
void preenchervazio(char *nome);
//imagem de interação com o usuário e animação pós-nascimento
void display();
//função para iniciação do tamagotchi a vida emfim
void nascimento();
//loop de interação maquina-usuário
void interacaousuario();
//condições aleatórias
void condicoesaleatorias();
//verificador fatalidades possíveis
int fatalidades(); // necessita do inteiro para terminar o jogo
//operador de nível do monstrinho
void niveldomonstrinho();
//obtém o nome, salva no ponteiro, copia o ponteiro para as auxiliares principais de funções main e display
void salvarNome();


#endif
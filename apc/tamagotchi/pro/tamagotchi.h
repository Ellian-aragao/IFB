#ifndef TAMAGOTCH_H
#define TAMAGOTCH_H

//função para limpeza da tela
void limpartela();
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
//verificador fatalidades possíveis
int fatalidades(); // necessita do inteiro para terminar o jogo
//operador de nível do monstrinho
void niveldomonstrinho();

#endif
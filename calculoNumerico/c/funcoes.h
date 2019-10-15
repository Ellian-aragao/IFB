#ifndef FUNCOES_H
#define FUNCOES_H

// calcula a função de X
float FdeX(float *coeficientes, int n, float X);
/*faz o cálculo da F(x), sendo esta definda com um número "n + 1" de coeficientes com n destes sendo multiplicados por um certo "x"
F(x) = a0 * x^0 + a1 * x^1+ a2 * x^2 + a3 * x^3 + a4 * x^4 + a5 * x^5 + a6 * x^6  */

// função de potência
float pot(double base, int potencia);
/*realiza a potenciação de uma certa base em cima da poência dada, sendo assim a base multiplicada por si mesma "potencia" vezes*/

// função fatorial
float fat(float n);
/*realiza o cálculo da função fatorial através do método recursivo*/

// polinomio de Taylor
float Taylor(float coeficiente, float x, int i);
/*retorna o cálculo da função de Taylor sendo o coeficiente vezes a potência de "x^i" */

// verifica se a alocação de memória funcionou
void testeDeAlocacao(void *ptr);
/*verifica se alocação da memória não returnara um valor NULL e baseado nisso encerra o programa, senão procede normalmente*/

// executa os testes para atualização dos limites e retorna um valor relativo ao ERRO
float verificador(float *limite, float *coeficientes, int n);
/*verifica o valor encontrado na função e testa as extremidade inferior e posterior, através do T.V.M determina se está dentro do escopo
do algorítimo, através da determinação se a multiplicação dos valores tem como resultado um número negativo, assim valendo o teorema
seu término ocorre quando o valor da média está dentro da precisão expressa na variável ERRO ou quando suas iterações */

// faz o calculo do ponto médio
float pontoMedio(float *limite);
/*realiza o cálculo do ponto médio através do padrão abaixo devolvendo o valor obtido
limite inferior + (limite superior - limite inferior) / 2 */

// limpa a tela para execusão das funções
void limpartela();

// executa o algoritmo da bisseccao
void bisseccao(void);

// executa o algoritmo de taylor
void taylor(void);

// realiza o teste para encontrar o epsilon da máquina
void epsilon(void);

#endif

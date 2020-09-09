#ifndef NUMEROCOMPLEXO_H
#define NUMEROCOMPLEXO_H

typedef struct numeroComplexo NUMERO_COMPLEXO;

NUMERO_COMPLEXO *criaNumeroComplexo(double real, double imaginario);
/**
 * aloca memória para numero complexo
 */
void liberaNumeroComplexo(NUMERO_COMPLEXO *numeroComplexo);
/**
 * faz a liberação da memória
 */
NUMERO_COMPLEXO *soma(NUMERO_COMPLEXO *num1, NUMERO_COMPLEXO *num2);
/**
 * faz a operação de soma
 */
NUMERO_COMPLEXO *subtracao(NUMERO_COMPLEXO *num1, NUMERO_COMPLEXO *num2);
/**
 * faz a operação de subtração
 */
NUMERO_COMPLEXO *divisao(NUMERO_COMPLEXO *num1, NUMERO_COMPLEXO *num2);
/**
 * faz a operação de divisão
 */
NUMERO_COMPLEXO *multiplicacao(NUMERO_COMPLEXO *num1, NUMERO_COMPLEXO *num2);
/**
 * faz a operação de multiplicação
 */

#endif

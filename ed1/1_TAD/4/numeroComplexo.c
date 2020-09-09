#include "numeroComplexo.h"
#include <stdio.h>
#include <stdlib.h>

struct numeroComplexo
{
  double real;
  double imaginario;
};

NUMERO_COMPLEXO *criaNumeroComplexo(double real, double imaginario)
{
  NUMERO_COMPLEXO *numeroComplexo = malloc(sizeof(NUMERO_COMPLEXO));
  if (numeroComplexo == NULL)
  {
    fprintf(stderr, "Erro ao criar Número Complexo\n");
    return NULL;
  }
  numeroComplexo->real = real;
  numeroComplexo->imaginario = imaginario;
  return numeroComplexo;
}

void liberaNumeroComplexo(NUMERO_COMPLEXO *numeroComplexo)
{
  free(numeroComplexo);
}

NUMERO_COMPLEXO *soma(NUMERO_COMPLEXO *num1, NUMERO_COMPLEXO *num2)
{
  return criaNumeroComplexo(num1->real + num2->real, num1->imaginario + num2->imaginario);
}

NUMERO_COMPLEXO *subtracao(NUMERO_COMPLEXO *num1, NUMERO_COMPLEXO *num2)
{
  return criaNumeroComplexo(num1->real - num2->real, num1->imaginario - num2->imaginario);
}

NUMERO_COMPLEXO *multiplicacao(NUMERO_COMPLEXO *num1, NUMERO_COMPLEXO *num2)
{
  return criaNumeroComplexo(
    num1->real * num2->real - num1->imaginario * num2->imaginario,
    num1->real * num2->imaginario + num1->imaginario * num2->real
  );
}

NUMERO_COMPLEXO *divisao(NUMERO_COMPLEXO *num1, NUMERO_COMPLEXO *num2)
{
  double baseDivisao = num2->real * num2->real + num2->imaginario * num2->imaginario;
  return criaNumeroComplexo(
    (num1->real * num2->real - num1->imaginario * num2->imaginario) / baseDivisao,
    (num1->real * num2->imaginario + num1->imaginario * num2->real) / baseDivisao
  );
}

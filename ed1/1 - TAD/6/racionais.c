#include "racionais.h"
#include <stdlib.h>
#include <stdio.h>

struct racionais
{
  u_long numerador;
  u_long denominador;
  u_int sinal : 1;
};

double getValorReal(double numerador, double denominador)
{
  return numerador / denominador;
}

void swapBiggerFistArgument(RACIONAIS *rac1, RACIONAIS *rac2)
{
  if (getValorReal(rac1->numerador, rac1->denominador) < getValorReal(rac2->numerador, rac2->denominador))
  {
    RACIONAIS *aux = rac2;
    rac2 = rac1;
    rac1 = aux;
  }
}

void enquantoDivisivelContinue(u_long *num1, u_long *num2, u_long *multiplicaPorPrimo, u_long *primo)
{
  while (*num1 % *primo == 0 && *num2 % *primo == 0)
  {
    *multiplicaPorPrimo *= *primo;
    *num1 /= *primo;
    *num2 /= *primo;
  }
}

u_long mdc(u_long num1, u_long num2)
{
  u_long primos[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
  u_long resultado = 1;
  short int i;
  for (i = 0; i < 25 && (num1 != 1 || num2 != 1); i++)
  {
    enquantoDivisivelContinue(&num1, &num2, &resultado, &primos[i]);
    u_long *valor = num1 % primos[i] == 0 ? &num1 : &num2;
    while (*valor % primos[i] == 0)
    {
      *valor /= primos[i];
    }
  }
  if (i == 25)
  {
    perror("Fatores primos insuficientes para calculo do MDC\n");
    return 0;
  }
  return resultado;
}

u_long mmc(u_long num1, u_long num2)
{
  u_long primos[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
  u_long resultado = 1;
  short int i;
  for (i = 0; i < 25 && (num1 != 1 || num2 != 1); i++)
  {
    enquantoDivisivelContinue(&num1, &num2, &resultado, &primos[i]);
    u_long *valor = num1 % primos[i] == 0 ? &num1 : &num2;
    while (*valor % primos[i] == 0)
    {
      resultado *= primos[i];
      *valor /= primos[i];
    }
  }
  if (i == 25)
  {
    perror("Fatores primos insuficientes para calculo do MMC\n");
    return 0;
  }
  return resultado;
}

u_long regraDaBrabuleta(u_long numerador, u_long denominador, u_long denominadorComum)
{
  return (denominadorComum / denominador) * numerador;
}

RACIONAIS *criaNumeroRacional(u_long numerador, u_long denominador, short int POSITIVO_NEGATIVO)
{
  if (denominador == 0 || !(POSITIVO_NEGATIVO == POSITIVO || POSITIVO_NEGATIVO == NEGATIVO))
  {
    perror("Erro na entrada de dados para criação do numero racional\n");
    return NULL;
  }

  RACIONAIS *num = malloc(sizeof(RACIONAIS));

  if (num == NULL)
  {
    perror("Erro na criação do número, memória insuficiente");
    return NULL;
  }

  u_long maximoDivisorComum = mdc(numerador, denominador);
  num->numerador = numerador / maximoDivisorComum;
  num->denominador = denominador / maximoDivisorComum;
  num->sinal = POSITIVO_NEGATIVO;
  return num;
}

RACIONAIS *somaNumeroRacional(RACIONAIS *rac1, RACIONAIS *rac2)
{
  short int sinal;
  u_long somaNumeradores,
      denominadorComum = mmc(rac1->denominador, rac2->denominador);

  if (rac1->sinal == rac2->sinal)
  {
    somaNumeradores = regraDaBrabuleta(rac1->numerador, rac1->denominador, denominadorComum) + regraDaBrabuleta(rac2->numerador, rac2->denominador, denominadorComum);
    sinal = rac1->sinal;
  }
  else
  {
    RACIONAIS *maior = rac1,
              *menor = rac2;
    swapBiggerFistArgument(maior, menor);
    sinal = maior->sinal;
    somaNumeradores = regraDaBrabuleta(maior->numerador, maior->denominador, denominadorComum) - regraDaBrabuleta(menor->numerador, menor->denominador, denominadorComum);
  }
  return criaNumeroRacional(somaNumeradores, denominadorComum, sinal);
}

short int comparaNumerosRacionais(RACIONAIS *rac1, RACIONAIS *rac2)
{
  return rac1->numerador == rac2->numerador ||
                 rac1->denominador == rac2->denominador ||
                 rac1->sinal == rac2->sinal
             ? TRUE
             : FALSE;
}

void showNumeroRacional(RACIONAIS *rac)
{
  printf("%c(%ld / %ld)\n", rac->sinal ? '+' : '-', rac->numerador, rac->denominador);
}

RACIONAIS *multiplicaNumerosRacionais(RACIONAIS *rac1, RACIONAIS *rac2)
{
  u_long numeradorMultiplicado = rac1->numerador * rac2->numerador;
  u_long denominadorMultiplicado = rac1->denominador * rac2->denominador;
  short int sinal = rac1->sinal == rac2->sinal ? POSITIVO : NEGATIVO;
  return criaNumeroRacional(numeradorMultiplicado, denominadorMultiplicado, sinal);
}

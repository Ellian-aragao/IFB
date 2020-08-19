#include "racionais.h"
#include <stdlib.h>
#include <stdio.h>

struct racionais
{
  u_long numerador;
  u_long denominador;
  u_int sinal : 1;
};

RACIONAIS *criaNumeroRacional(u_long numerador, u_long denominador, u_int positivoTRUE_negativoFALSE)
{
  if (denominador == 0 || positivoTRUE_negativoFALSE > 1 || positivoTRUE_negativoFALSE < 0)
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

  num->numerador = numerador;
  num->denominador = denominador;
  num->sinal = positivoTRUE_negativoFALSE;

  return num;
}

// RACIONAIS *somaNumeroRacional(RACIONAIS *rac1, RACIONAIS *rac2)
// {
//   u_long denominadorComum = mmc(rac1->denominador, rac2->denominador);
//   u_long somaNumeradores = regraDaBrabuleta(rac1, denominadorComum) + regraDaBrabuleta(rac2, denominadorComum);
//   u_long sinal = 0;

//   return criaNumeroRacional(somaNumeradores, denominadorComum, sinal);
// }

u_long regraDaBrabuleta(u_long *rac, u_long denominadorComum)
{
  return 0;
}

u_long mmc(u_long num1, u_long num2)
{
  const u_long primos[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
  u_long fatorPrimo = 1;
  for (short int i = 0; i < 25 && (num1 != 1 || num2 != 1); i++)
  {
    const char *stringParaPrintf = "| %02ld , %02ld  | primo-> %02ld |\n";

    while (num1 % primos[i] == 0 && num2 % primos[i] == 0)
    {
      printf(stringParaPrintf, num1, num2, primos[i]);
      fatorPrimo *= primos[i];
      num1 /= primos[i];
      num2 /= primos[i];
    }

    u_long *valor = num1 % primos[i] == 0 ? &num1 : &num2;

    while (*valor % primos[i] == 0)
    {
      printf(stringParaPrintf, num1, num2, primos[i]);
      fatorPrimo *= primos[i];
      *valor /= primos[i];
    }
  }
  return fatorPrimo;
}

int main(int argc, char const *argv[])
{
  printf("%ld\n", mmc(12, 45));
  return 0;
}

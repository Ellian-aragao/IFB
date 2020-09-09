#ifndef RACIONAIS_H
#define RACIONAIS_H

#define TRUE 1
#define FALSE 0

#define POSITIVO 1
#define NEGATIVO 0

typedef struct racionais RACIONAIS;
typedef unsigned long u_long;

RACIONAIS *criaNumeroRacional(u_long numerador, u_long denominador, short int POSITIVO_NEGATIVO);
RACIONAIS *somaNumeroRacional(RACIONAIS *rac1, RACIONAIS *rac2);
RACIONAIS *multiplicaNumerosRacionais(RACIONAIS *rac1, RACIONAIS *rac2);
short int comparaNumerosRacionais(RACIONAIS *rac1, RACIONAIS *rac2);
void showNumeroRacional(RACIONAIS *rac);

#endif

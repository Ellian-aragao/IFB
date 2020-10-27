#ifndef ALUNO_H
#define ALUNO_H

#include <stdlib.h>
#include <string.h>

typedef struct pessoa {
  int Matricula;
  char Nome[30];
  float Nota;
}Pessoa;

Pessoa *criaPessoa();
void setPessoa(Pessoa *p, int matricula, const char *nome, float nota);
int getMatricula(Pessoa *p);
char *getNome(Pessoa *p);
float getNota(Pessoa *p);

#endif
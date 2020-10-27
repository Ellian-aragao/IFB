#include "21.h"

Pessoa *criaPessoa()
{
  Pessoa *p = malloc(sizeof(Pessoa));
  if (!p)
    exit(EXIT_FAILURE);
  return p;
}

void setPessoa(Pessoa *p, int matricula, const char *nome, float nota)
{
  p->Matricula = matricula;
  strcpy(p->Nome, nome);
  p->Nota = nota;
}

int getMatricula(Pessoa *p)
{
  return p->Matricula;
}

char *getNome(Pessoa *p)
{
  return p->Nome;
}

float getNota(Pessoa *p)
{
  return p->Nota;
}
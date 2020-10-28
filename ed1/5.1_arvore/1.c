#include <stdio.h>
#include <stdlib.h>

typedef struct Produto
{
  int matricula;
  float preco;
} Produto;

typedef struct No
{
  Produto p;
  No *left;
  No *right;
} No;

No **create_heap()
{
  No **no = malloc(sizeof(No*));
  if (!no)
  {
    perror("Erro na criação da árvore");
    exit(EXIT_FAILURE);
  }
  
  return no;
}

No *new_set_node(int matricula, float preco)
{
  No *no = create_heap();
  no->p.matricula = matricula;
  no->p.preco = preco;
  return no;
}

No *find_matricula(No *no, int *matricula)
{
  if (!no)
    return no;
  if (no->p.matricula == *matricula)
    return no;
  if (no->p.matricula < *matricula)
    return find_matricula(no->left, matricula);
  return find_matricula(no->right, matricula);
}

void adicionar(No *no, int matricula, float preco)
{
  if (no)
  {
    No *tmp = find_matricula(no, &matricula);
    if (tmp)
      perror("Já existe a matrícula indicada");
    else
      tmp = new_set_node(matricula, preco);
  }
  no = new_set_node(matricula, preco);
}
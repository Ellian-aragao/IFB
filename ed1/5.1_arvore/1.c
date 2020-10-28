#include "1.h"
#define BIGGER(a, b) (a) > (b) ? (a) : (b)

static float get_matricula(No *node)
{
  return node->p.matricula;
}
static float get_preco(No *node)
{
  return node->p.preco;
}
static inline void isNullExitFailure(void *pointer, const char *str)
{
  if (!pointer)
  {
    perror(str);
    exit(EXIT_FAILURE);
  }
}
No **create_heap()
{
  No **no = malloc(sizeof(No *));
  isNullExitFailure(no, "Erro na criação da árvore");
  return no;
}
static inline No *create_node(int matricula, float preco)
{
  No *no = malloc(sizeof(No));
  isNullExitFailure(no, "Erro na criação do nó");
  no->p.matricula = matricula;
  no->p.preco = preco;
  no->left = NULL;
  no->right = NULL;
  return no;
}

static No *find_matricula(No *no, int *matricula)
{
  if (!no)
    return no;
  if (no->p.matricula == *matricula)
    return no;
  if (no->p.matricula < *matricula)
    return find_matricula(no->left, matricula);
  return find_matricula(no->right, matricula);
}

int adicionar(No **heap, int matricula, float preco)
{
  No *node = *heap;
  if (node && (node = find_matricula(node, &matricula)))
    return 0;
  node = create_node(matricula, preco);
  return 1;
}

void preco(No **heap, int matricula)
{
  No *node = find_matricula(*heap, &matricula);
  if (node)
    return (void)printf("O produto '%d' custa R$%.2f\n", node->p.matricula, node->p.preco);
  return perror("Erro: produto não encontrado!");
}

static int nodes_heap_recursive(No *node)
{
  if (node)
    return 1 + nodes_heap_recursive(node->left) + nodes_heap_recursive(node->right);
  return 0;
}

int nodes_heap(No **heap)
{
  if (*heap)
    return nodes_heap_recursive(*heap);
  return -1;
}

static int num_folhas_recursive(No *no)
{
  if (no && no->left || no->right)
    return num_folhas_recursive(no->left) + num_folhas_recursive(no->right);
  return 1;
}

int num_folhas(No **heap)
{
  if (*heap)
    return num_folhas_recursive(*heap);
  return 0;
}

static int tam_heap_recursive(No *no)
{
  if (no && no->left || no->right)
    return BIGGER(num_folhas_recursive(no->left), num_folhas_recursive(no->right));
  return 1;
}

int tam_heap(No **heap)
{
  if (*heap)
    return tam_heap_recursive(*heap);
  return 0;
}

static int maior_preco_recursive(No *no)
{
  if (no)
  {
    int maior = no->p.preco;
    if (no->left)
      maior = BIGGER(BIGGER(maior, no->left->p.preco), maior_preco_recursive(no->left));
    if (no->right)
      maior = BIGGER(BIGGER(maior, no->right->p.preco), maior_preco_recursive(no->right));
    return maior;
  }
  return 0;
}

static float maior_atributo_recursive(No *no, float (*get_atribute_produto)(No *))
{
  if (no)
  {
    float maior = get_atribute_produto(no);
    if (no->left)
      maior = BIGGER(BIGGER(maior, get_atribute_produto(no->left)), maior_atributo_recursive(no->left, get_atribute_produto));
    if (no->right)
      maior = BIGGER(BIGGER(maior, get_atribute_produto(no->right)), maior_atributo_recursive(no->right, get_atribute_produto));
    return maior;
  }
  return 0;
}

int maior_preco(No **heap)
{
  if (*heap)
    return maior_preco_recursive(*heap);
  return -1;
}

static No *remove_node_copy(No *node, No *remove)
{
  node->p = remove->p;
  node->left = remove->left;
  node->right = remove->right;
  return remove;
}

static void remove_node(No *node)
{
  No *tmp;
  if (node->left && node->right)
  {
    int maiorMatricula = maior_atributo_recursive(node->left, get_matricula);
    tmp = find_matricula(node->left, &maiorMatricula);
    node->p = tmp->p;
  }
  else if (node->left)
    tmp = remove_node_copy(node, node->left);
  else if (node->right)
    tmp = remove_node_copy(node, node->right);
  free(node);
}

int remove_heap(No **heap, int matricula)
{
  if (*heap)
  {
    No *node = find_matricula(*heap, &matricula);
    if (node)
    {
      remove_node(node);
      return 1;
    }
    perror("Nó inexistênte");
    return 0;
  }
  perror("Árvore vazia");
  return -1;
}

int verifica_avl(No **heap)
{
  No *node = *heap;
  int boolean = 1;
  if (
      (node) &&
      (boolean = verifica_avl(&(node->left))) &&
      (boolean = verifica_avl(&(node->right))))
  {
    const unsigned int diff = tam_heap_recursive(node->left) - tam_heap_recursive(node->right);
    if (1 < diff)
      boolean = 0;
  }
  return boolean;
}

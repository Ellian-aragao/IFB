#include "../LinkedList/linkedList.h"
#include "quantosParesExistemNaLista.h"
#include "stdio.h"

int main(int argc, char const *argv[])
{
  LinkedList *listaUlong = createLinkedList(sizeof(u_long));
  for (size_t i = 0; i < 10; i++)
  {
    appendLinkedList(listaUlong, &i);
  }
  u_long quantosInteiros = quantosParesExistemNaLista(listaUlong);
  printf("existem '%ld' numeros pares na lista\n", quantosInteiros);
  return 0;
}

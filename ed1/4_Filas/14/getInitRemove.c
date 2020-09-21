#include "getInitRemove.h"

void *getInitRemove(Queue *queue)
{
  const size_t tamItem = getSizeofItensOfQueue(queue);
  void *item = malloc(tamItem);
  if (!item)
  {
    perror("Erro na alocação do item para retornar");
    exit(EXIT_FAILURE);
  }
  memcpy(item, getItemQueue(queue),tamItem);
  removeQueue(queue);
  return item;
}

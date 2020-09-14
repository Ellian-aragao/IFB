#include "linkedListToArray.h"

static void *arrayList;
static u_long i;
static size_t sizeofItensLinkedList;

static inline void isNullExit(void *ptr)
{
  if (!ptr)
  {
    perror("Erro ao alocar memória para arrayList");
    exit(EXIT_FAILURE);
  }
}

void saveInArray(void *item)
{
  memcpy(arrayList + (i++ * sizeofItensLinkedList), item, sizeofItensLinkedList);
}

void *linkedToArray(LinkedList *list)
{
  sizeofItensLinkedList = getSizeofItensLinkedList(list);
  arrayList = malloc(getTamLinkedList(list) * sizeofItensLinkedList);
  isNullExit(arrayList);
  forEachLinkedList(list, saveInArray);
  return arrayList;
}
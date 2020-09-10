#include "poligono.h"

#define voidToVerticeX(ptr) ((*(Vertice *)ptr).x)
#define voidToVerticeY(ptr) ((*(Vertice *)ptr).y)
#define voidToVerticeNextVertice(ptr) ((*(Vertice *)ptr).proximoVertice)
Vertice *verticeAnterior = NULL;

static int comparadorVertice(void *item1, void *item2)
{
  if (voidToVerticeX(item1) == voidToVerticeX(item2) &&
      voidToVerticeY(item1) == voidToVerticeY(item2))
    return 1;
  return 0;
}

static void printVertice(void *v)
{
  printf("(%.1f,%.1f),", voidToVerticeX(v), voidToVerticeY(v));
}

static void printVerticeNextVertice(void *v)
{
  printf("(%.1f,%.1f)->", voidToVerticeX(v), voidToVerticeY(v));
  void *ptrNext;
  if ((ptrNext = voidToVerticeNextVertice(v)) != NULL)
  {
    printVertice(ptrNext);
  }
}

Poligono *createPoligono()
{
  return createLinkedList(sizeof(Vertice));
}

void destroyPoligono(Poligono *p)
{
  destroyLinkedList(p);
}

Vertice *createVerticeAndAddInPoligono(Poligono *p, float x, float y)
{
  Vertice v = {x, y, NULL};
  return appendLinkedList(p, &v);
}

Vertice *addVerticeInPoligono(Poligono *p, Vertice *v)
{
  return appendLinkedList(p, v);
}

void removeVertice(Poligono *p, Vertice *v)
{
  removeItemLinkedList(p, v, comparadorVertice);
}

void printPoligono(Poligono *p)
{
  putchar('{');
  forEachLinkedList(p, printVertice);
  puts("}");
}

void printVerticeApontaParaQualVertice(Poligono *p)
{
  forEachLinkedList(p, printVerticeNextVertice);
  putchar('\n');
}

void setProximoVertice(Vertice *vertice_origem, Vertice *vertice_destino)
{
  vertice_origem->proximoVertice = vertice_destino;
}

void linkVerticesDoPoligonoForEach(void *ptr)
{
  if (verticeAnterior != NULL)
    setProximoVertice(verticeAnterior, ptr);
  verticeAnterior = ptr;
}

void linkVerticesSequencialmente(Poligono *p)
{
  forEachLinkedList(p, linkVerticesDoPoligonoForEach);
  setProximoVertice(getItemByIndex(p, getTamLinkedList(p) - 1), getItemByIndex(p, 0));
}

Vertice *getVerticeByIndex(Poligono *p, u_long index)
{
  return getItemByIndex(p, index);
}
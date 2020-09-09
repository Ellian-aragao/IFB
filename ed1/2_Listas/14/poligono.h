#ifndef LINKEDLIST_H
#include "../LinkedList/linkedList.h"
#endif

#ifndef POLIGONO_H
#define POLIGONO_H

typedef LinkedList Poligono;
typedef struct vertice Vertice;
struct vertice
{
  float x;
  float y;
  Vertice *proximoVertice;
};

// cria a lista do polígono
Poligono *createPoligono();
// destroi a lista do poligono
void destroyPoligono(Poligono *p);
// cria o vertice através dos valores x e y passados como parâmetro
Vertice *createVerticeAndAddInPoligono(Poligono *p, float x, float y);
// adiciona a estrutura do vertice no polígono
Vertice *addVerticeInPoligono(Poligono *p, Vertice *v);
// remove um vertice do polígono
void removeVertice(Poligono *p, Vertice *v);
// exibe os vertices do polígono
void printPoligono(Poligono *p);
// configura a ligação do vertice com o próximo para formação da linha
void setProximoVertice(Vertice *vertice_origem, Vertice *vertice_destino);
// liga os vertices sequencialmente conforme foram adicionados no polígono
void linkVerticesSequencialmente(Poligono *p);
// exibe todos os vertices e para qual vertice apontam
void printVerticeApontaParaQualVertice(Poligono *p);
// acessa o vertice através do indice
Vertice *getVerticeByIndex(Poligono *p, u_long index);

#endif
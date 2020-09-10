#include "poligono.h"

int main()
{
  Poligono *p = createPoligono();
  for (float i = 0; i < 5; i++)
    createVerticeAndAddInPoligono(p, i, i * 2);
  printPoligono(p);
  linkVerticesSequencialmente(p);
  printVerticeApontaParaQualVertice(p);
  destroyPoligono(p);
  return 0;
}

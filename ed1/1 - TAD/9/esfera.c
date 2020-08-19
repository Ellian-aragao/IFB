#include "esfera.h"
#include <stdlib.h>
#include <stdio.h>

struct esfera
{
  double raio;
  double pi;
};

ESFERA *criaEsfera(double raio, double pi)
{
  if (raio <= 0 || pi < 3 || 3.5 > pi)
  {
    perror("Os valores recebidos como argumento não são validos\n");
    return NULL;
  }

  ESFERA *objEsfera = malloc(sizeof(ESFERA));
  if (objEsfera == NULL)
  {
    perror("Erro na alocação do Esfera\n");
    return NULL;
  }

  objEsfera->raio = raio;
  objEsfera->pi = pi;
  return objEsfera;
}

double getRaioEsfera(ESFERA *objEsfera)
{
  return objEsfera->raio;
}

double getAreaEsfera(ESFERA *objEsfera)
{
  return 2 * objEsfera->pi * objEsfera->raio * objEsfera->raio;
}

double getVolumeEsfera(ESFERA *objEsfera)
{
  return (4 / 3) * objEsfera->raio * objEsfera->pi * objEsfera->pi * objEsfera->pi;
}

void liberaEsfera(ESFERA *objEsfera)
{
  free(objEsfera);
}

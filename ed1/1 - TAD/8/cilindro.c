#include "cilindro.h"
#include <stdlib.h>
#include <stdio.h>

struct cilindro
{
  double raio;
  double pi;
  double geratriz;
};

CILINDRO* criaCilindro(double raio, double valorPi, double geratriz)
{
  if (raio <= 0 || valorPi < 3 || 3.5 > valorPi || geratriz <= 0)
  {
    perror("Os valores recebidos como argumento não são validos\n");
    return NULL;
  }
  
  CILINDRO* objCilindro = malloc(sizeof(CILINDRO));
  if (objCilindro == NULL)
  {
    perror("Erro na alocação do cilindro\n");
    return NULL;
  }
  
  objCilindro->raio = raio;
  objCilindro->pi = valorPi;
  objCilindro->geratriz = geratriz;
  return objCilindro;
}

double getAlturaCilindro(CILINDRO* objCilindro)
{
  return objCilindro->geratriz;
}

double getAreaBaseCilindro(CILINDRO* objCilindro)
{
  return objCilindro->raio * objCilindro->raio * objCilindro->pi;
}

double getAreaLateralCilindro(CILINDRO* objCilindro)
{
  return 2 * objCilindro->geratriz * objCilindro->raio * objCilindro->pi;
}

double getAreaTotal(CILINDRO* objCilindro)
{
  return 2 * getAreaBaseCilindro(objCilindro) + getAreaLateralCilindro(objCilindro);
}

double getVolumeCilindro(CILINDRO* objCilindro)
{
  return objCilindro->geratriz * getAreaBaseCilindro(objCilindro);
}

void liberaCilindro(CILINDRO* objCilindro)
{
  free(objCilindro);
}

#include "cubo.h"
#include <stdlib.h>
#include <stdio.h>

struct cubo
{
  double lado;
};

CUBO* criaCubo(double lado)
{
  if (lado <= 0)
  {
    perror("Os valores recebidos como argumento não são validos\n");
    return NULL;
  }
  
  CUBO* objCubo = malloc(sizeof(CUBO));
  if (objCubo == NULL)
  {
    perror("Erro na alocação do cubo\n");
    return NULL;
  }
  
  objCubo->lado = lado;
  return objCubo;
}

double getAreaFaceCubo(CUBO* objCubo)
{
  return objCubo->lado * objCubo->lado;
}

double getAreaTotalCubo(CUBO* objCubo)
{
  return 6 * getAreaFaceCubo(objCubo);
}

double getVolumeCubo(CUBO* objCubo)
{
  return objCubo->lado * getAreaFaceCubo(objCubo);
}

void liberaCubo(CUBO* objCubo)
{
  free(objCubo);
}

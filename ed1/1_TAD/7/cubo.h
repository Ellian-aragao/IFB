#ifndef CUBO_H
#define CUBO_H

typedef struct cubo CUBO;

CUBO* criaCubo(double lado);
double getAreaFaceCubo(CUBO* objCubo);
double getAreaTotalCubo(CUBO* objCubo);
double getVolumeCubo(CUBO* objCubo);
void liberaCubo(CUBO* objCubo);

#endif
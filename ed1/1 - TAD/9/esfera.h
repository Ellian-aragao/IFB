#ifndef ESFERA_H
#define ESFERA_H

typedef struct esfera ESFERA;

ESFERA *criaEsfera(double raio, double pi);
double getRaioEsfera(ESFERA *objEsfera);
double getAreaEsfera(ESFERA *objEsfera);
double getVolumeEsfera(ESFERA *objEsfera);
void liberaEsfera(ESFERA *objEsfera);

#endif
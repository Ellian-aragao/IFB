#ifndef CILINDRO_H
#define CILINDRO_H

typedef struct cilindro CILINDRO;

CILINDRO* criaCilindro(double raio, double valorPi, double geratriz);
double getAlturaCilindro(CILINDRO* objCilindro);
double getAreaBaseCilindro(CILINDRO* objCilindro);
double getAreaLateralCilindro(CILINDRO* objCilindro);
double getAreaTotal(CILINDRO* objCilindro);
double getVolumeCilindro(CILINDRO* objCilindro);
void liberaCilindro(CILINDRO* objCilindro);

#endif

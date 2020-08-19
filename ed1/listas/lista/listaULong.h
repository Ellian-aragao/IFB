#ifndef LISTAULONG_H
#define LISTAULONG_H
#define TRUE  1
#define FALSE 0
typedef unsigned long u_long;
typedef short int intzinho;
typedef struct conjuntoULong listaULong;
u_long multiplicaTodosOsTermos(listaULong *conj);
intzinho insereListaUlong(listaULong *conjunto, u_long valorAdicionar);
void liberaListaULong(listaULong *conj);
listaULong *criaListaULong();
#endif

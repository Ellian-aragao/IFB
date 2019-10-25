#include <stdio.h>
#include "dinamiclist.h"
typedef struct elemento{
    aluno alunoi;
    aluno* ptr_elemento;
}elemento;

elemento* elemento_cria()
{
    elemento* el = (elemento*) malloc(sizeof(elemento));
    if (el != NULL) *el = NULL;
    return el;
}



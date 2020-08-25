#ifndef REMOVENPRIMEIROSITENSLISTA_H
#define REMOVENPRIMEIROSITENSLISTA_H

typedef struct structExemplo ListaDinamica;
typedef unsigned long u_long;
typedef struct itemQualquer {
/**
 * insira qualquer tipo de dado a ser adicionado na lista
**/
} DADO;

/**
 * retorna ponteiro para listaDinamica que armazena o tipo de dado definido acima
**/
ListaDinamica *createListaDinamica();

/**
 * insere itens no final da lista, sempre ao final da lista
**/
void appendListaDinamica(ListaDinamica *lista, DADO dadoToAppend);

/**
 * remove os primeiros itens da lista, em desejo de apagar a lista, passar o tamanho dela
**/
int removeNprimeirosItensListaDinamica(ListaDinamica* lista, u_long numeroDeItensParaEliminar);

/**
 * retorna o tamanho da lista
**/
u_long getTamListaDinamica(ListaDinamica lista);

#endif
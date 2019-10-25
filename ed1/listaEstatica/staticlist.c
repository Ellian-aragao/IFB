#include <stdio.h>
#include "staticlist.h"
turma* turma_cria()
{
    turma* t1 = malloc(sizeof(turma));
    if (t1 != NULL) t1->quantidade = 0;
    else puts("ERROR");
    return t1;
}
// libera a turma
void turma_libera(turma* t1)
{
    free(t1);
}
// retorna a quantidade de turmas
int turma_tamanho(turma* t1)
{
    if(t1 == NULL) return -1;
    return t1->quantidade;
}
// retorna se a lista está cheia
int turma_cheia(turma* t1)
{
    if (t1 == NULL) return -1;
    return (t1->quantidade == TAM);
}
int turma_vazia(turma* t1)
{
    if (t1 == NULL) return -1;
    return (t1->quantidade == 0);
}
int turma_insere_ordenado(turma* t1, aluno a1)
{
    if (t1 == NULL) return -1;
    else if (turma_cheia(t1)) return 0;
    int i = 0;
    // conta até o elemento intermediário do aluno em relação a matricula
    while(i < t1->quantidade && t1->alunos[i].matricula < a1.matricula) i++;
    // realiza a cópia dos elementos para o ponto posterior para add aluno no ponto intermediário
    for (int k = t1->quantidade - 1; k >= i; k--) t1->alunos[k + 1] = t1->alunos[k];
    // inserção do aluno no ponto intermediário
    t1->alunos[i] = a1;
    t1->quantidade++;
    return 1;
}
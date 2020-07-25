#include <stdio.h>
#include <stdlib.h>
#include "staticlist.h"

TURMA* turma_cria()
{
    TURMA* t1 = malloc(sizeof(TURMA));
    if (t1 != NULL) t1->quantidade = 0;
    else puts("ERROR");
    return t1;
}
void turma_libera(TURMA* t1)
{
    free(t1);
}
int turma_tamanho(TURMA* t1)
{
    if(t1 == NULL) return -1;
    return t1->quantidade;
}
int turma_cheia(TURMA* t1)
{
    if (t1 == NULL) return -1;
    return (t1->quantidade == TAM);
}
int turma_vazia(TURMA* t1)
{
    if (t1 == NULL) return -1;
    return (t1->quantidade == 0);
}
int turma_insere_ordenado(TURMA* t1, ALUNO a1)
{
    if (t1 == NULL) return -1;
    else if (turma_cheia(t1)) return 0;
    int i = 0;
    // conta até o elemento intermediário do aluno em relação a matrícula
    while(i < t1->quantidade && t1->alunos[i].matricula < a1.matricula) i++;
    // realiza a cópia dos elementos para o ponto posterior para add aluno no ponto intermediário
    for (int k = t1->quantidade - 1; k >= i; k--) t1->alunos[k + 1] = t1->alunos[k];
    // inserção do aluno no ponto intermediário
    t1->alunos[i] = a1;
    t1->quantidade++;
    return 1;
}
int turma_remove_ordenado(TURMA* t1, ALUNO a1)
{
    if (t1 == NULL) return -1;
    else if (turma_vazia(t1)) return 0;
    int i = 0;
    // percorre a turma para encontrar a matrícula do aluno a ser removido
    while (i < t1->quantidade && t1->alunos[i].matricula != a1.matricula) i++;
    // verifica se o loop encontrou o aluno a ser removido
    if (t1->alunos[i].matricula != a1.matricula) return 0;
    // atualiza as posições da turma conforme a matrícula
    while (i < t1->quantidade)
    {
        t1->alunos[i] = t1->alunos[i+1];
        i++;
    }
    t1->quantidade--;
    return 1;
}
int turma_consulta_posicao(TURMA* t1, int posicao, ALUNO* a1)
{
    if (t1 == NULL || posicao <= 0 ||t1->quantidade > posicao) return 0;
    *a1 = t1->alunos[posicao - 1];
    return 1;
}
int turma_consulta_busca_matricula(TURMA* t1,int matricula, ALUNO* a1)
{
    if (t1 == NULL) return 0;
    int i = 0;
    // percorre até encontrar a matrícula do aluno na turma
    while (i < t1->quantidade && t1->alunos[i].matricula != matricula) i++;
    // verifica se a matrícula atual é do aluno desejado
    if (matricula != t1->alunos[i].matricula) return 0;
    *a1 = t1->alunos[i];
    return 1;
}
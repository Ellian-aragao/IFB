#ifndef STATICLIST_H
#define STATICLIST_H
#define TAM 30
typedef struct aluno{
    int matricula;
    char nome[20];
    float n1,n2,n3;
}aluno;
turma* turma_cria();
void turma_libera(turma* t1);
int turma_tamanho(turma* t1);
int turma_cheia(turma* t1);
int turma_vazia(turma* t1);
int turma_insere_ordenado(turma* t1, aluno a1);
int turma_remove_ordenado(turma* t1, aluno a1);
int turma_consulta_posicao(turma* t1, int posicao, aluno* a1);
int turma_consulta_busca_matricula(turma* t1,int matricula, aluno* a1);
#endif
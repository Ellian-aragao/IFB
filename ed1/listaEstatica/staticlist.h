#ifndef STATICLIST_H
#define STATICLIST_H
#define TAM 30
typedef struct turma{
    int quantidade;
    aluno alunos[TAM];
}turma;
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
#endif
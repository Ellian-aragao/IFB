#ifndef STATICLIST_H
#define STATICLIST_H
#define TAM 30
typedef struct aluno{
    int matricula;
    char nome[20];
    float n1,n2,n3;
}ALUNO;
typedef struct turma{
    int quantidade;
    ALUNO alunos[TAM];
}TURMA;
TURMA* turma_cria();
void turma_libera(TURMA* t1);
int turma_tamanho(TURMA* t1);
int turma_cheia(TURMA* t1);
int turma_vazia(TURMA* t1);
int turma_insere_ordenado(TURMA* t1, ALUNO a1);
int turma_remove_ordenado(TURMA* t1, ALUNO a1);
int turma_consulta_posicao(TURMA* t1, int posicao, ALUNO* a1);
int turma_consulta_busca_matricula(TURMA* t1,int matricula, ALUNO* a1);
#endif
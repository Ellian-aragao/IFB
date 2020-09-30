// algoritmo reaproveitado da lista de tad

typedef unsigned long u_long;
#define TRUE 1
#define FALSE 0

int testaSePertence(const int *vetor, const int tam, int numeroProcurado, int *index)
{
  int limiteInferior = 0,
      LimiteSuperior = tam == 0 ? 0 : tam - 1;
  
  while (TRUE)
  {
    int mediana = limiteInferior + (LimiteSuperior - limiteInferior) / 2;
    if (numeroProcurado < vetor[mediana])
    {
      LimiteSuperior = mediana;
    }
    else if (vetor[mediana] < numeroProcurado)
    {
      limiteInferior = mediana;
    }
    else if (vetor[mediana] == numeroProcurado)
    {
      *index = mediana;
      return TRUE;
    }
    if ((limiteInferior + 1) == LimiteSuperior)
      return FALSE;
  }
}

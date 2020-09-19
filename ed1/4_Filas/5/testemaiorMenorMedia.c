#include "maiorMenorMedia.h"

int main()
{
  Queue *q = createQueue(4);
  for (int i = 0; i < 5; i++)
    addQueue(q,&i);
  MAIORMENORMEDIA a = getMinMaxMedia(q);
  printf("%d min, %d max, %f media\n",a.menor,a.maior,a.media);
  destroyQueue(q);
  return 0;
}

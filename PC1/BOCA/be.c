#include <stdio.h>
int main()
{
  int n,k;
  scanf("%d %d", &n,&k);
  if (n >= 1 && n <= 1000)
  {
    if (k >= 0 && k <= 95)
    {
      char texto[80];
      fflush(stdin);
      fgets(texto, 80, stdin);
      for (int i = 0; texto[i-1] != '\0'; i++)
      {
        if(texto[i] + k <= 125) texto[i] += k;
        else texto[i] = ((texto[i] + k) % 125) + 32;
      }

      printf("\n%s",texto);
    }
      else puts("error");
  }
  else puts("error");


  return 0;
}

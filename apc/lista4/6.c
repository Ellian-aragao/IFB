#include<stdio.h>
int main(){
	char x0,x1;
	printf("digite 2 letras que deseja converter ao ASCII\n");
	scanf("%c %c",&x0,&x1);
	printf("o char '%c' e '%c' em ASCII sao respectivamente '%d' e '%d'\n",x0,x1,(int)x0,(int)x1);
}
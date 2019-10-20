#include<stdio.h>
int main(){
	int s0,s1,t0,t1;
	printf("digite a distancia inicial em metros\n");
	scanf("%d",&s0);
	printf("digite a distancia final em metros\n");
	scanf("%d",&s1);
	printf("digite o tempo inicial em segundos\n");
	scanf("%d",&t0);
	printf("digite o tempo final em segundos\n");
	scanf("%d",&t1);
	printf("a velocidade media do objeto e %d metros/segundo\n",(s1-s0)/(t1-t0));
}
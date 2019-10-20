#include<stdio.h>
int main(){
	float x1,x3;
	int x2;
	printf("digite um numero float\n");
	scanf("%f",&x1);
	x2=(int)x1;
	x3=x1-x2;
	printf("o numero %.4f e formado pela parte inteira %d e pela parte decimal %.4f \n",x1,x2,x3);
}
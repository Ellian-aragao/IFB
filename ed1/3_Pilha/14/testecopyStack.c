#include "copyStack.h"

int main()
{
	Stack *s = createStack(4);
	for (int i = 0; i < 10; i++)
		pushStack(s, &i);
	Stack *copyS = copyStack(s);
	puts(isEqualLinkedLists(s, copyS) ? "iguais" : "diferentes");
	destroyStack(s);
	destroyStack(copyS);
	return 0;
}

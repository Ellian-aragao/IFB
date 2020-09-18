#include "equalStacks.h"

int main()
{
	Stack *s1 = createStack(4),
				*s2 = createStack(4);
	// int a = -1;
	// pushStack(s1, &a);
	// a = -2;
	// pushStack(s2, &a);
	for (int i = 0; i < 3; i++)
	{
		pushStack(s1, &i);
		pushStack(s2, &i);
	}
	puts(isEqualStacks(s1, s2) ? "iguais" : "diferentes");
	destroyStack(s1);
	destroyStack(s2);
	return 0;
}

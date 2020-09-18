#pragma once

#include "../PilhaInterface/Stack.h"


/****************************************************************
 * faz a comparação de quantidade de intens salvos na pilha 
 *  -1 : s1 < s2
 *   0 : s1 = s2
 *   1 : s1 > s2
*******************************************************************/
int compareTamStack(Stack *s1, Stack *s2);
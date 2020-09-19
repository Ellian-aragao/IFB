#pragma once

#include "../FilaInterface/Queue.h"


/****************************************************************
 * faz a comparação de quantidade de intens salvos na fila 
 *  -1 : s1 < s2
 *   0 : s1 = s2
 *   1 : s1 > s2
*******************************************************************/
int compareTamQueue(Queue *q1, Queue *q2);
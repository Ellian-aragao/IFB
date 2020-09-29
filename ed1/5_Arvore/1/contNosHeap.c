#include "../Heap/Heap.h"

int main()
{
  Heap *h = 
  criaHeap(
    NULL,
    criaHeap(
        NULL,
        criaHeap(
            NULL,
            NULL,
            NULL
        ),
        criaHeap(
            NULL,
            NULL,
            NULL
        )
    ),
    criaHeap(
        NULL,
        criaHeap(
            NULL,
            NULL,
            NULL
        ),
        criaHeap(
            NULL,
            NULL,
            criaHeap(
                NULL,
                criaHeap(
                    NULL,
                    NULL,
                    NULL
                ),
                NULL
            )
        )
    )
  );
  printf("%ld\n", tamHeap(h));
  printf("%ld\n", tamHeapLeaves(h));
  destroyHeap(h);
  return 0;
}

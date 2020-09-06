#!/bin/bash
cd '/home/ellian/code/faculdade/ed1/2 - Listas/LinkedList/'
# gcc -g linkedList.c testInterface/testLinkedListInterface.c testeLinkedList.c
gcc -c -g linkedList.c #testInterface/testLinkedListInterface.c

# pathTest="/home/ellian/code/faculdade/ed1/2 - Listas/8/"

mv 'linkedList.o' '../14'
# mv 'testLinkedListInterface.o' '../8'
cd '../14/'

gcc -g linkedList.o mediaDeTodosOsNumeros.c testemediaDeTodosOsNumeros.c
rm linkedList.o
./a.out
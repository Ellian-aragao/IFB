#!/bin/bash
cd '/home/ellian/code/faculdade/ed1/2 - Listas/LinkedList/'
# gcc -g linkedList.c testInterface/testLinkedListInterface.c testeLinkedList.c
gcc -c -g linkedList.c testInterface/testLinkedListInterface.c

# pathTest="/home/ellian/code/faculdade/ed1/2 - Listas/8/"

mv 'linkedList.o' '../8'
mv 'testLinkedListInterface.o' '../8'
cd '../8/'

gcc -g getBiggerElementAndIndexOfLinkedList.c testegetBiggerElementAndIndexOfLinkedList.c linkedList.o testLinkedListInterface.o
./a.out
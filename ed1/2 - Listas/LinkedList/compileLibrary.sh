#!/bin/bash
cd '/home/ellian/code/faculdade/ed1/2 - Listas/LinkedList/'
# gcc -g linkedList.c testInterface/testLinkedListInterface.c testeLinkedList.c
gcc -c -g linkedList.c testInterface/testLinkedListInterface.c

# pathTest="/home/ellian/code/faculdade/ed1/2 - Listas/8/"

mv 'linkedList.o' '../15'
mv 'testLinkedListInterface.o' '../15'
cd '../15/'

gcc -g linkedList.o testLinkedListInterface.o verificaSeEstaOrdenado.c testeverificaSeEstaOrdenado.c
rm linkedList.o testLinkedListInterface.o
./a.out
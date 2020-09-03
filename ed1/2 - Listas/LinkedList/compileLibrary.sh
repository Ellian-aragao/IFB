#!/bin/bash
cd '/home/ellian/code/faculdade/ed1/2 - Listas/LinkedList/'
# gcc -g linkedList.c testInterface/testLinkedListInterface.c testeLinkedList.c
gcc -c -g linkedList.c testInterface/testLinkedListInterface.c

pathTest=`/home/ellian/code/faculdade/ed1/2 - Listas/7/encadeada`

# mv 'linkedList.o' `$pathTest`
# mv 'testLinkedListInterface.o' `$pathTest`
echo "var $pathTest"
cd `$pathTest`
pwd
# gcc -g concatenaLinkedList.c testaConcatenaLinkedList.c linkedList.o testLinkedListInterface.o
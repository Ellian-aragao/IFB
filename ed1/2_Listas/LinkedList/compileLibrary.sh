#!/bin/bash

#faz a compilação da biblioteca
compile_library() {
  echo 'Compilando biblioteca LinkedList'
  gcc -c -g linkedList.c testInterface/testLinkedListInterface.c
}

# gera binário final utilizando o teste do exercício e a interface dele com a biblioteca
compile_exercicio() {
  echo 'Compilando binário final'
  gcc -g $(ls *.c *.o)
  rm $(ls *.o)
}

# move os arquivos da biblioteca para pasta destino
move_library() {
  dest=$1
  mv linkedList.o $dest
  mv testLinkedListInterface.o $dest
  cd $dest
}

echo_binario_final_fail() {
  echo -e '\n*****************************'
  echo      '! Binário final inexistente !'
  echo      "*****************************"
}

# executa binário padrão gerado pelo compilador gcc
execute_binary() {
  if [ -s "a.out" ]; then
    echo -e 'Executando exercício\n--------------------\n'
    ./a.out
    rm a.out
  else
    echo_binario_final_fail
  fi
}

# faz a compilação conforme parâmetro enviado como argumento
fluxo_execucao() {
  if [ -z $1 ]; then
    echo 'não foi enviado path'
    exit
  elif [ "$1" != "LinkedList" ] && [ "$1" != "LinkedList/" ]; then
    compile_library
    move_library $pathLista$1
  else
    gcc -c -g testInterface/testLinkedListInterface.c
  fi
  compile_exercicio
  execute_binary
}

pathLista=~/code/faculdade/ed1/2_Listas/
path=$1

cd $pathLista/LinkedList
fluxo_execucao $path

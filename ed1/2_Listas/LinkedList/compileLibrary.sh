#!/bin/bash

#faz a compilação da biblioteca
compile_library() {
  echo 'Compilando biblioteca LinkedList'
  gcc -c $compileFlags -Wextra linkedList.c testInterface/testLinkedListInterface.c
}

# gera binário final utilizando o teste do exercício e a interface dele com a biblioteca
compile_exercicio() {
  echo 'Compilando binário final'
  gcc $compileFlags $(ls *.c *.o)
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
  echo '! Binário final inexistente !'
  echo "*****************************"
}

# executa binário padrão gerado pelo compilador gcc
execute_binary() {
  if [ -s "a.out" ]; then
    echo -e 'Executando exercício\n--------------------\n'
    valgrind -s \
         --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=valgrind-out.txt \
    ./a.out
       
    # valgrind \
    # ./a.out
    rm a.out
  else
    echo_binario_final_fail
  fi
}

# faz a compilação conforme parâmetro enviado como argumento
fluxo_execucao() {
  # exclui casos que não existe path
  if [ -z $1 ]; then
    echo 'não foi enviado path'
    exit

  # vefifica se a path não é da biblioteca LinkedList
  elif [ "$1" != "LinkedList" ] && [ "$1" != "LinkedList/" ]; then
    compile_library
    move_library $pathLista$1

  # se é da bilbioteca faz a compilação da API de teste
  else
    gcc -c $compileFlags testInterface/testLinkedListInterface.c
  fi

  compile_exercicio
  execute_binary
}

compileFlags='-g -W -Wall -Wextra -Wshadow '
pathLista=~/code/faculdade/ed1/2_Listas/
path=$1

cd $pathLista/LinkedList
fluxo_execucao $path

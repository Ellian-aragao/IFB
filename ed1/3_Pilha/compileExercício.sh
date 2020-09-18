#!/bin/bash

compile_library() {
  if [ ! -s  "linkedList.o" ]; then
    gcc -c $compileFlags ../2_Listas/LinkedList/linkedList.c
  fi
  if [ ! -s  "Stack.o" ]; then
    gcc -c $compileFlags ./PilhaInterface/Stack.c
  fi
}

# gera binário final utilizando o teste do exercício e a interface dele com a biblioteca
compile_exercicio() {
  echo 'Compilando binário final: '$pathStack
  gcc $compileFlags $(ls $pathDoProgramaPraCompilar/*.c *.o)
}

echo_binario_final_fail() {
  echo -e '\n*****************************'
  echo '! Binário final inexistente !'
  echo "*****************************"
}

# verifica argumento de debug
type_execution_binary() {
  # 1: simples em terminal
  # 2: completa txt separado
  # defaut: none
  case $debugOption in
  1)
    valgrind \
      ./a.out
    ;;
  2)
    valgrind -s \
      --leak-check=full \
      --show-leak-kinds=all \
      --track-origins=yes \
      --verbose \
      --log-file=valgrind-out.txt \
      ./a.out
    ;;
  *)
    ./a.out
    ;;
  esac
}

# executa binário padrão gerado pelo compilador gcc
execute_binary() {
  # verifica se existe o binário
  if [ -s "a.out" ]; then
    echo -e 'Executando exercício\n--------------------\n'
    type_execution_binary
    if [ -z $dontDeletBinary ]; then
      rm a.out
    fi
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
  fi

  compile_library
  compile_exercicio
  execute_binary
}

# variáveis globais para programa
compileFlags='-g -W -Wall -Wextra -Wshadow -Werror'
pathStack=~/code/faculdade/ed1/3_Pilha/

# variáveis enviadas pelo usuário
pathDoProgramaPraCompilar=$1
debugOption=$2
dontDeletBinary=$3

cd $pathStack
fluxo_execucao $pathDoProgramaPraCompilar $debugOption

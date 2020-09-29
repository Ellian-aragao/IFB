#!/bin/bash

# script para compilação automática e execução dos exercícios
# 1ºarg: (obrigatório) executar e enviar path relativa ao shell do programa a compilar
# 2ºarg: modo de execução do escript, fora utilizado valgrind para analise de memória
# 3ºarg: um caracter qualquer para indicar que não deseja deletar o binário final pós execução

compile_library() {
  # if [ ! -s "linkedList.o" ]; then
  #   gcc -c $compileFlags ../2_Listas/LinkedList/linkedList.c
  # fi
  # if [ ! -s "Heap.o" ]; then
    gcc -c $compileFlags ./Heap/Heap.c
  # fi
}

# gera binário final utilizando o teste do exercício e a interface dele com a biblioteca
compile_exercicio() {
  echo 'Compilando binário final: '$path
  gcc $compileFlags $(ls $pathDoProgramaPraCompilar/*.c *.o)
}

# mostra erro na compilação do programa
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
  elif [ ! -d $1 ]; then
    echo 'diretório enviado não existe'
    exit
  fi

  compile_library
  compile_exercicio
  execute_binary
}

# variáveis globais para programa
compileFlags='-g -W -Wall -Wextra -Wshadow -Werror'
path=~/code/faculdade/ed1/5_Arvore

# variáveis enviadas pelo usuário
pathDoProgramaPraCompilar=$1
debugOption=$2
dontDeletBinary=$3

cd $path
fluxo_execucao $pathDoProgramaPraCompilar $debugOption

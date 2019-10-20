# -*- coding: utf-8 -*-
"""
Created on Sun Aug 19 14:58:42 2018

@author: Dhiego Loiola de Araújo

Implementação do método da bissecção
"""

import numpy as np
import matplotlib.pyplot as plt

a = 0
b = 10
num_iter = 100
erro = 1e-2


# definir uma função de teste
def f_2(x):
    return x**5+22*x**3-8*x**2-18*x


# função dropwave
def f_1(x):
    return -(1-np.cos(12*np.sqrt(x**2)))/(0.5*np.sqrt(x**2)+2)


def f_0(x):
    return x**2-2**(-x)


def f_3(x):
    return x**3 - 3*x**2*(2**(-x))+3*x*(4**(-x))-8**(-x)


a0 = a
b0 = b
x = 1e5*np.ones((num_iter))
graf = np.ones_like(x)

# utilizar a função escolhida
f = f_0

# atualização do ponto x
for i in range(num_iter):
    if abs(b0-a0) < erro:
        break
    else:
        x[i] = a0+(b0-a0)/2
        f0 = f(a0)
        f1 = f(b0)
        fmed = f(x[i])
        if np.sign(f1)*np.sign(fmed) < 0:
            a0 = x[i]
            if abs(b0-a0) < erro:
                break
        if np.sign(f0)*np.sign(fmed) < 0:
            b0 = x[i]
            if abs(b0-a0) < erro:
                break
    print(i, a0, b0, x[i], f(x[i]))
    graf[i] = f(x[i])

# fazer o gráfico dos valores de x
fig = plt.figure(1)
plt.plot(x[0:i], 'b.-')
plt.title('Valores de $x$ por iteração')
plt.xlabel('Iterações')
plt.ylabel('Valores aproximados')
# mostrar o valor do último ponto
plt.text(i-1, x[i-1], x[i-1])

# gráfico de execução do algoritmo
fig = plt.figure(2)
plt.plot(x[0:i], f(x[0:i]), 'ro-.')
# mostrar a ordem dos pontos no gráfico
for k in range(i):
    plt.text(x[k], f(x[k]), k)
plt.title('Execução do algoritmo')
plt.show()

def FdeX(x):  # função de x
    return (- 0.1 * x ** 4 - 0.15 * x ** 3 - 0.5 * x ** 2 - 0.25 * x + 1.2)


def Taylor(coeficientes, x, i):  # função de Taylor
    return (coeficientes * x ** i)


# coeficientes dados pela lista
coeficientes = [1.2, -0.25, -0.5, -0.15, -0.1]

# intervalo dado [0,4] que foi dividido em dez partes
x = [0, 0.4, 0.8, 1.2, 1.6, 2.0, 2.4, 2.8, 3.2, 3.6, 4]

# alterando os valores de x
for i in x:
    taylor = 0
    fdex = FdeX(i)
    # realizando as iterações de taylor para chegar no valor de f(x)
    for j in range(len(coeficientes)):
        taylor += Taylor(coeficientes[j], i, j)
        print(j, i, taylor, fdex)

        # critério de parada quando elementos são iguais
        if abs(taylor - fdex) < 1e-3:
            break
    print('\n\n')

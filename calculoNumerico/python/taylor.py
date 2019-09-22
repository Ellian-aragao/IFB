def FdeX(x):  # função de x
    return (- 0.1 * x ** 4 - 0.15 * x ** 3 - 0.5 * x ** 2 - 0.25 * x + 1.2)


def Taylor(coeficientes, x, i):  # função de Taylor
    return ( coeficientes * pow(x, i))


# coeficientes dados pela lista
coeficientes = [- 0.1, - 0.15, - 0.5, - 0.25, 1.2]
# intervalo dado [0,4] que foi dividido em dez partes
x = [0, 0.4, 0.8, 1.2, 1.6, 2.0, 2.4, 2.8, 3.2, 3.6, 4]
coeficientes.reverse()

for i in x:
    print('quando x = {}'.format(i))
    taylor = 0
    for j in range(0, 4):
        taylor = Taylor(coeficientes[j], i, j)
        print(taylor, FdeX(i))

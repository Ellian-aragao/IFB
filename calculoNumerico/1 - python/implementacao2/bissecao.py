def h(coeficientes, x):
    return (Taylor(coeficientes, x) - FdeX(x) - 10e-3)

""" fazer correção no polinômio de taylor em função da atualização do grau dele para o cálculo da bicessao """
def Taylor(coeficientes, x, limite_i):  # função de Taylor por cálculo direto
    taylor = 0
    # cálculo completo da função
    for i in coeficientes:
        taylor += (coeficientes * x ** i)
        
    return taylor


def FdeX(x):  # função de x
    return (- 0.1 * x ** 4 - 0.15 * x ** 3 - 0.5 * x ** 2 - 0.25 * x + 1.2)


def ponto_medio(lim_inferior, lim_superior):
    return (lim_superior + (lim_superior - lim_inferior) / 2)


def bisseccao(lim_inferior, lim_superior, x):
    taylor = Taylor(coeficientes, x)
    fdex = FdeX(x)
    while abs(taylor - fdex - 1e-3) > 1e-4:
        medio = ponto_medio(lim_inferior, lim_superior)
        
        if h(coeficientes, medio) < 0:

        else:
            


# coeficientes dados pela lista
coeficientes = [1.2, -0.25, -0.5, -0.15, -0.1]

    
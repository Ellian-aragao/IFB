from __future__ import division
import matplotlib.pyplot as mpl
import math as m

eixox = []
eixoy = []
n = []
y = []
n_taylor = []
y_taylor = []

x = 0
for j in range (0, 361, 20):
    cosX = 0
    x = m.radians(j)
    for i in range(0, 30):
        sinal = (-1)**i
        num = x**(2*i)
        denom = m.factorial(2*i)
        cosX += (sinal) * ((num/denom))
    y_taylor.append(cosX)
    n_taylor.append(j)


for i in range (0, 361):
    n.append(i)
    y.append(m.cos(m.radians(i)))


for a in range(0,361):
    eixox.append(a)
    eixoy.append(0)


mpl.plot(eixox,eixoy, linestyle = 'dotted',color = '#000000', label = 'eixo x')
mpl.plot(n,y, label = 'cos(x)')
mpl.plot(n_taylor,y_taylor, linestyle = 'dotted', color = '#FF0000', linewidth= 3, label = 'cos(x)_Taylor')
mpl.ylabel('cos(x)')
mpl.xlabel('x')
mpl.legend()
mpl.show()

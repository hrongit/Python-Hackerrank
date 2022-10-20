#https://www.hackerrank.com/contests/k21qt-contest33/challenges/np-array-mathematics


import numpy as np
n, m = map(int, input().split())
a = [np.array(input().split(), int) for _ in range(n)]
b = [np.array(input().split(), int) for _ in range(n)]
functions = [np.add, np.subtract, np.multiply, np.floor_divide, np.mod, np.power]
for fn in functions:
    print(np.array(fn(a,b)))
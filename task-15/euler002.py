

import sys

def fib(n):
    L = [1, 1]
    while True:
        c = L[-1] + L[-2]
        if c > n:
            break
        L.append(c)
    return L


t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    series=fib(n)
    evenlist=[series[x] for x in range(2, len(series), 3)]
    print(sum(evenlist))
    
   




import sys

def prfcts(n):
    
    factors = []
    d = 2
    while n > 1:
        while n % d == 0:
            factors.append(d)
            n /= d
        d = d + 1
        if d*d > n:
            if n > 1: factors.append(n)
            break
        
    return factors

t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    L = prfcts(n)
    print(int(max(L)))
    


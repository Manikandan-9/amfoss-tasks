import sys


def sum1(a,b):
    d = a // b
    return b * (d * (d+1)) // 2

t = int(input().strip())
if t<=10**5 and t>=1: 
    for a0 in range(t):
        sum=0
        n = int(input().strip())
        if n<=10**9 and n>=1:
            ans=sum1(n-1, 3) + sum1(n-1, 5) - sum1(n-1, 15)
            print(ans)

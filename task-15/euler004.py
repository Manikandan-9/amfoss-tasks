

import sys

def palindrome_number(n):
    palindrome = 0
    for i in range(100,1000):
        if i%11==0:
            for j in range(100,1000):
                prod = i * j
                if str(prod) == str(prod)[::-1]:
                    if prod > palindrome and prod < n:
                        palindrome = prod
    return palindrome
    
t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    print(palindrome_number(n))

                



import sys

def CheckDivisibleByN(number,n):
    for i in range(1,n+1):
        if number%i!=0:
            return False
    else:
        return True
t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    number = 1
    while True:
        if CheckDivisibleByN(number,n):
            break
        else:
            number+=1
    print(number)
   
    


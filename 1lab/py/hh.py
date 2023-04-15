import math
n = int(input())
def isPrime(n):
    for i in range (2,int(math.sqrt(n))+1):
        if (n % i ==0):
            return False
    return True
if isPrime(n) and n > 1:
    print('YES')
else : print('NO')
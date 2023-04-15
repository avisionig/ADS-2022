import math
n = int(input())
def isPrime(n):
    if n == 1 or n == 0:
        return "NO"
    for i in range (2,math.ceil(n ** 0.5)):
        if (n % i ==0):
            return "NO"
    return "YES"
print(isPrime(n))
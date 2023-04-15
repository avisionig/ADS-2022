import math
def nthPrime(n):
    list = [True for i in range(n * n + 1)]
    i = 2
    while i * i <= n * n:
        if list[i] == True:
            for j in range(i * i, n * n + 1, i):
                list[j] = False
        i += 1
    c = 0
    for i in range(2, n * n + 1):
        if c == n : return i 
        elif list[i] == True: c += 1
n = int(input())
if (n == 1):
    print(2)
else : print(nthPrime(n))
def primes(n, list):
    list[0], list[1] = False, False
    for i in range(2, n * n):
        list[i] = True
    for i in range(2, n * n ):
        if (i * i <= n * n and list[i] == True):
            for j in range(i * 2,n * n ,i):
                list[j] = False
                i += 1
def superPrime(n):
    list = [1 for i in range(n * n )]
    primes(n, list)
    superprimes = [0 for i in range(2,n * n )]
    j = 0
    for i in range(2,n * n ):
       if (list[i]):
           superprimes[j] = i
           j += 1
    
    for k in range(j):
        if (list[k + 1]):
            c = superprimes[k]
    return c
n = int(input()) + 1
print(superPrime(n))
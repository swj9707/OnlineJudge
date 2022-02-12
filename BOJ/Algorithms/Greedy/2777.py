import sys ; input = lambda : sys.stdin.readline().rstrip()

def factorize(n):
    factor = 2 
    factors = []
    while (factor**2 <= n): 
        while (n % factor == 0):
            if factor < 11:
                factors.append(factor) 
                n = n // factor  
            else:
                factors.clear()
                return factors
        factor += 1
    if n > 1 :
        if n < 11:
            factors.append(n)
        else:
            factors.clear()
    return factors

T = int(input())



for _ in range(T):
    N = int(input())
    dataList = factorize(N)
    if len(dataList) == 0:
        print(-1)
    else:
        print(dataList)
    

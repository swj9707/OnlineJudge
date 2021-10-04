def factorial(N):
    return N * factorial(N-1) if N > 1 else 1

N = int(input())
print(factorial(N))


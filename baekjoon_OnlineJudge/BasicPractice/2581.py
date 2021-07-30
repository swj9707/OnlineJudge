import sys

input = lambda : sys.stdin.readline().rstrip()

M = int(input())
N = int(input())

def is_prime_number(x):
    if x > 1:
        for i in range(2, x):
            if x % i == 0:
                return False 
        return True
    else:
        return False

sum = 0
first = 0
for i in range(M, N+1):
    if is_prime_number(i):
        if sum == 0:
            first = i
        sum += i

if sum == 0:
    print(-1)
else:
    print(sum)
    print(first)    
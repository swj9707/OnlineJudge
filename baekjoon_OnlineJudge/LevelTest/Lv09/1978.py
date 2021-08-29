import sys

input = lambda : sys.stdin.readline().rstrip()

def isPrime(N):
    if N == 1: return False;
    else:
        for i in range(2, N):
            if N % i == 0:
                return False
        return True

N = input()
answer = 0
data = list(input().split())
for i in data:
    if isPrime(int(i)):
        answer += 1

print(answer)
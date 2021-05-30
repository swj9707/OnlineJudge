import sys
input = lambda : sys.stdin.readline().rstrip()

def answer(k, n):
    downstair = [int(i + 1) for i in range(n)]
    for i in range(k):
        for j in range(1, n):
            downstair[j] += downstair[j-1]
    return downstair[n-1]
T = int(input())

for _ in range(T):
    k = int(input())
    n = int(input())
    print(answer(k, n))

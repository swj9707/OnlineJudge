import sys
input = lambda : sys.stdin.readline().rstrip()

T = int(input())

for i in range(T):
    S = int(input())
    n = int(input())
    for j in range(n):
        q, p = map(int, input().split())
        S += q * p
    print(S)


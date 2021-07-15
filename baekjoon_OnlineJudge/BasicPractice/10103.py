import sys
input = lambda : sys.stdin.readline().rstrip()

N = int(input())

A = 100
B = 100

for _ in range(N):
    n, m = map(int, input().split())
    if n > m:
        B -= n
    elif n < m:
        A -= m

print(A)
print(B)

import sys

N,X = map(int,sys.stdin.readline().rstrip().split())

a = list(map(int, sys.stdin.readline().rstrip().split()))

for i in range(N):
    if a[i] < X:
        print(a[i], end=' ')




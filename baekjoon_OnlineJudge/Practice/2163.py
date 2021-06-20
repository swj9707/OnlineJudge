import sys
input = lambda : sys.stdin.readline().rstrip()

N, M = map(int, input().split())
print((N-1) + N*(M-1))

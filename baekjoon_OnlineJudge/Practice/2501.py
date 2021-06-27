import sys

input = lambda : sys.stdin.readline().rstrip()

N, K = map(int, input().split())

result = []
for _ in range(1, N + 1):
    if N % _ == 0:
        result.append(_)

if len(result) >= K:
    print(result[K-1])
else:
    print(0)
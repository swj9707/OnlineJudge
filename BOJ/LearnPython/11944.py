import sys ; input = lambda : sys.stdin.readline().rstrip()

N, M = map(int, input().split())

answer = str(N) * N
if len(answer) > M:
    print(answer[:M])
else:
    print(answer)
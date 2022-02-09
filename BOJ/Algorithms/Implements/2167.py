import sys; input = lambda : sys.stdin.readline().rstrip()

N, M = map(int, input().split())

DP = [[0]*(M+1) for _ in range(N+1)]
lst = [list(map(int, input().split())) for _ in range(N)]

for i in range(1, N+1):
    for j in range(1, M+1):
        DP[i][j] = lst[i-1][j-1] + DP[i][j-1] + DP[i-1][j] - DP[i-1][j-1]

K = int(input())

for _ in range(K):
    i, j, x, y = map(int, input().split())

    print(DP[x][y] - DP[x][j-1] - DP[i-1][y] + DP[i-1][j-1])
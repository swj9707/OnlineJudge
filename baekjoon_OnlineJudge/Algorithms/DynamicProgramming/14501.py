import sys ; input = lambda : sys.stdin.readline().rstrip()

N = int(input())
T = []
P = []
dp = []
for _ in range(N):
    t, p = map(int, input().split())
    T.append(t)
    P.append(p)
    dp.append(p)
dp.append(0)

for i in range(len(T)-2, -1, -1):
    if T[i] + i <= N:
        dp[i] = max(P[i] + dp[i + T[i]], dp[i+1])
    else:
        dp[i] = dp[i+1]
print(dp[0])

import sys ; input = lambda : sys.stdin.readline().rstrip()

N = int(input())
T = []
P = []
dp = [0 for i in range(N)]
for _ in range(N):
    t, p = map(int, input().split())
    T.append(t)
    P.append(p)
dp.append(0)

for i in range(N-1, -1, -1):
    if T[i] + i > N:
        dp[i] = dp[i+1]
    else:
        dp[i] = max(dp[i+1], p[i] + dp[i + T[i]])
print(dp[0])
    

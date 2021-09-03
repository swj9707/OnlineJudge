import sys ; input = lambda : sys.stdin.readline().rstrip()

N = int(input())

dp = [0,1,2]

for i in range(3, 1001):
    dp.append(dp[i-2] + dp[i-1])

print(dp[N])


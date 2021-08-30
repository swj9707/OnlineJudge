import sys ; input = lambda : sys.stdin.readline().rstrip()

T = int(input())

dp = [1,2,4]

for i in range(4, 100000):
    dp.append(dp[i-3] % 1000000009 + dp[i-2] % 1000000009 + dp[i-1] % 1000000009)

for i in range(T):
    N = int(input())
    print(dp[N-1])
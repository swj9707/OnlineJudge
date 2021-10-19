import sys ; input = lambda : sys.stdin.readline().rstrip()

T = int(input())
for _ in range(T):
    dp = [1,2,4]
    data = int(input())
    for i in range(3, data):
        dp.append(dp[i-1] + dp[i-2] + dp[i-3])
    print(dp[data-1])

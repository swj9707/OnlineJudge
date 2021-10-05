import sys ; input = lambda : sys.stdin.readline().rstrip()

T = int(input())

for _ in range(T):
    N, M = map(int, input().split())
    answer = 0
    for i in range(N, M+1):
        for j in str(i):
            if j == '0':
                answer += 1
    print(answer)

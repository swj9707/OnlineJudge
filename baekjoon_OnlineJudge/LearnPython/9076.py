import sys ; input = lambda : sys.stdin.readline().rstrip()

T = int(input())
for _ in range(T):
    data = list(map(int, input().split()))
    data.remove(max(data))
    data.remove(min(data))
    fullScore = sum(data)
    if max(data) - min(data) >= 4:
        print('KIN')
    else:
        print(fullScore)
import sys ; input = lambda : sys.stdin.readline().rstrip()

N = int(input())

data = []
for _ in range(N):
    data.append(list(map(int, input().split())))
data = sorted(data, key = lambda x : x[0])
data = sorted(data, key = lambda x : x[1])

print(data)
import sys ; input = lambda : sys.stdin.readline().rstrip()

N = int(input())

data = []
for _ in range(N):
    data.append(list(map(int, input().split())))
data = sorted(data, key = lambda x : x[0])
data = sorted(data, key = lambda x : x[1])

answer = 0
start = 0

for i in data:
    if i[0] >= start:
        start = i[1]
        answer += 1

print(answer)

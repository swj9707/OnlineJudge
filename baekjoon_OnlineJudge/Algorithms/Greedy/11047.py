import sys

input = lambda : sys.stdin.readline().rstrip()

N, K = map(int, input().split())

data = []

for i in range(N):
    data.append(int(input()))

count = 0
for i in reversed(range(N)):
    if K // data[i] != 0:
        count += (K // data[i])
        K = K % data[i]

print(count)

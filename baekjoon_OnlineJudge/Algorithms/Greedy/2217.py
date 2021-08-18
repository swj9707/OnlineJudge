import sys

input = lambda : sys.stdin.readline().rstrip()

N = int(input())

data = []

for _ in range(N):
	data.append(int(input()))

data.sort(reverse=True)

for _ in range(N):
	data[_] = data[_] * (_ + 1)

print(max(data)
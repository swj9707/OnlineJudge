import sys

input = lambda : sys.stdin.readline().rstrip()

N = int(input())

data = list(map(int, input().split()))

sum = 0

data.sort()

for i in range(len(data)):
    for j in range(i+1):
        sum += data[j]

print(sum)

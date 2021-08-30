import sys

input = lambda : sys.stdin.readline().rstrip()

data = list(map(int, input().split()))
data.sort()
for i in data:
    print(i, end=' ')
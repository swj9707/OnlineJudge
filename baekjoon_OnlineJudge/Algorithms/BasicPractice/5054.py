import sys

input = lambda : sys.stdin.readline().rstrip()

t = int(input())

for _ in range(t):
    n = int(input())
    data = list(map(int, input().split()))
    data.sort()
    sum = 0
    for i in range(0, len(data) - 1):
        sum += data[i + 1] - data[i] 
    print(sum*2)


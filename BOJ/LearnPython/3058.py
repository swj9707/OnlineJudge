import sys

input = lambda : sys.stdin.readline().rstrip()

T = int(input())

for i in range(T):
    data = list(map(int, input().split()))
    even = []
    for j in data:
        if j % 2 == 0:
            even.append(j)
    even.sort()
    print(sum(even), end=' ')
    print(even[0])
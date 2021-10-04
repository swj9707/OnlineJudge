import sys

input = lambda : sys.stdin.readline().rstrip()
data = []
for i in range(5):
    data.append(sum(list[map(int, input().split())]))

print(data.index(max(data))+1, max(data))


import sys

input = lambda : sys.stdin.readline().rstrip()
data = []
for i in range(8):
    data.append(int(input()))

sortedData = sorted(data, reverse=True)[:5]

print(sum(sortedData))
for i in data:
    if i in sortedData:
        print(data.index(i)+1, end=' ')


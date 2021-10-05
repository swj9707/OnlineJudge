import sys
input = lambda : sys.stdin.readline().rstrip()

data = list(input().split())
for i in range(len(data)):
    data[i] = int(data[i])
data.sort()
print(data[1])

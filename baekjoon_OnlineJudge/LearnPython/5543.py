import sys

input = lambda : sys.stdin.readline().rstrip()
data = []
for i in range(5):
    data.append(int(input()))
result = []
for i in range(0, 3):
    result.append(data[i]+data[3]-50)
    result.append(data[i]+data[4]-50)

result.sort()
print(result[0])

import sys

input = lambda : sys.stdin.readline().rstrip()

data = [int(input) for i in range(10)]
print(sum(data)//10)
print(max(data, key = data.count))

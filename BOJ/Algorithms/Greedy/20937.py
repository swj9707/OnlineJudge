import sys ; input = lambda : sys.stdin.readline().rstrip()

N = int(input())

data = map(int, input().split())
print(data)
numbers = [0] * 500001
for i in data:
    numbers[i] += 1
print(max(numbers))
import sys
input = lambda : sys.stdin.readline().rstrip()

N = int(input())
data = list(map(int, input().split()))
score = 1
result = 0

for i in data:
    if i == 1:
        result += score
        score += 1
    elif i == 0:
        score = 1

print(result)

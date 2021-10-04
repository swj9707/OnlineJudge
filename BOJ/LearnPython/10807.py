import sys

input = lambda : sys.stdin.readline().rstrip()

N = int(input())
data = list(map(int, input().split()))
V = int(input())
answer = 0
for i in data:
    if i == V:
        answer += 1

print(answer)

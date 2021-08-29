import sys

input = lambda : sys.stdin.readline().rstrip()

N = list(input().split('-'))
answer = ''
for i in N:
    answer += i[0]
print(answer)

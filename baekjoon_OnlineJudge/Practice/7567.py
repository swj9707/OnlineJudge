import sys
input = lambda : sys.stdin.readline().rstrip()

data = input()

answer = 0

if data[0] == '(':
    answer += 10
else:
    answer += 5

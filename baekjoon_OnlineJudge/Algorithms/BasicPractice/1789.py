import sys
input = lambda : sys.stdin.readline().rstrip()

S = int(input())

tmp = 1
answer = 0

while True:
    S -= tmp

    if S >= 0:
        answer += 1
        tmp += 1
    else:
        print(answer)
        break

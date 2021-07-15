import sys
input = lambda : sys.stdin.readline().rstrip()

def answer(a, b, c):
    if a == b == c:
        return 10000+a*1000
    elif a == b:
        return 1000+a*100
    elif a == c:
        return 1000+a*100
    elif b == c:
        return 1000+b*100
    else:
        return 100 * max(a,b,c)

N = int(input())

maxValue = 0
for _ in range(N):
    a, b, c = map(int, input().split())
    if maxValue < answer(a,b,c):
        maxValue = answer(a,b,c)
print(maxValue)


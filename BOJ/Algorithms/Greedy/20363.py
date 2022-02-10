import sys; input = lambda : sys.stdin.readline().rstrip()

X, Y = map(int, input().split())
answer = (X + Y) + Y // 10 if X >= Y else (X + Y) + X // 10
print(answer)
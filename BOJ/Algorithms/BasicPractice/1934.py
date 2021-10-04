import sys

input = lambda : sys.stdin.readline().rstrip()

def LCM(X, Y):
    if X < Y:
        max = Y
    else:
        max = X
    for i in range(max, (X*Y)+1):
        if i % X == 0 and i % Y == 0:
            res = i
            break
    return res


T = int(input())

for _ in range(T):
    A, B = map(int, input().split())
    print(LCM(A,B))

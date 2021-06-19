import sys
input = lambda : sys.stdin.readline().rstrip()

T = int(input())

for _ in range(T):
    Y = 0
    K = 0
    for i in range(9):
        A, B = map(int, input().split())
        if A > B:
            Y += 1
        elif A < B:
            K += 1
    if Y > K:
        print('Yonsei')
    elif Y < K:
        print('korea')
    else:
        print('Draw')

import sys

T = int(sys.stdin.readline().rstrip())

for _ in range(T):
    X, Y = map(int, sys.stdin.readline().rstrip().split())
    length = Y - X
    N = 0
    if length == 1:
        print('1')
    elif length == 0:
        print('0')
    else:
        while (N*(N+1))/2 < length:
            N += 1
        print(N+1)


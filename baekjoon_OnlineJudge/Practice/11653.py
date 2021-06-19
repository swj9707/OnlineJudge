import sys
input = lambda : sys.stdin.readline().rstrip()

N = int(input())

if N != 1:
    op = 2
    while N != 1:
        if N % op == 0:
            N /= op
            print(op)
        else:
            op += 1

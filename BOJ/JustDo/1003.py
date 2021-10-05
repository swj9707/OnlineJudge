import sys

N = int(sys.stdin.readline().rstrip())
for i in range(N):
    a = int(sys.stdin.readline().rstrip())
    zero = 1
    one = 0 
    tmp = 0

    for j in range(a):
        tmp = one
        one = one + zero
        zero = tmp
    print(zero, one)
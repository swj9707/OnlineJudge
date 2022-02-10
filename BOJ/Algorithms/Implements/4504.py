import sys ; input = lambda : sys.stdin.readline().rstrip()

N = int(input())
while True:
    X = int(input())
    if X == 0:
        break
    else:
        if X % N == 0:
            print("{} is a multiple of {}.".format(X, N))
        else:
            print("{} is NOT a multiple of {}.".format(X, N))
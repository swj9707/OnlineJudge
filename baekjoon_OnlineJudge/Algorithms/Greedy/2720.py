import sys

input = lambda : sys.stdin.readline().rstrip()

T = int(input())

for _ in range(T):
    C = int(input())
    Q = C // 25
    C = C % 25
    D = C // 10
    C = C % 10
    N = C // 5
    C = C % 5
    P = C // 1

    print("%d %d %d %d" % (Q,D,N,P))

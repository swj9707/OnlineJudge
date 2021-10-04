import sys

N = int(sys.stdin.readline().rstrip())

for _ in range(N):
    A, B = map(str, sys.stdin.readline().rstrip().split())
    for i in B:
        print(i*int(A),end='')
    print('')


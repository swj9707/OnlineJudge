import sys

N = int(sys.stdin.readline().rstrip())


for i in range(N):
    A, B = map(int, sys.stdin.readline().rstrip().split())
    print('Case #%s: %s'%(i+1, A+B))
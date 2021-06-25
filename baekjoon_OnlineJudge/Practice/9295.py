import sys
input = lambda : sys.stdin.readline().rstrip()

X = int(input())

for i in range(X):
    A, B = map(int, input().split())
    print('Case %d: %d'%(i+1, A+B))

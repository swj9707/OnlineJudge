import sys

N = int(sys.stdin.readline().rstrip())

case = []

for _ in range(N):
    A, B = map(int, sys.stdin.readline().rstrip().split())
    case.append((A,B))

for i in case:
    print(i[0]+i[1])


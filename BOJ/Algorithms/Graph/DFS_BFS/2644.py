import sys ; input = lambda : sys.stdin.readline().rstrip()
from collections import deque

def BFS(src, dest):
    Q = deque()
    Q.append(src)
    while(Q):
        X = Q.popleft()
        if(X == dest):
            return dist[dest]
        for i in range(len(V[X])):
            Y = V[X][i]
            if dist[Y] == 0:
                Q.append(Y)
                dist[Y] = dist[X] + 1
    return -1

N = int(input())
dist = [0]*(N+1)
V = [[]for _ in range(N+1)]
A, B = map(int, input().split())
M = int(input())
for _ in range(M):
    X, Y = map(int, input().split())
    V[X].append(Y)
    V[Y].append(X)
print(BFS(A, B))

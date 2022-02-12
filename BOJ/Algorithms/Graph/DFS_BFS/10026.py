import sys ; input = lambda : sys.stdin.readline().rstrip()
from collections import deque

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

N = int(input())
MATRIX = list(list(map(str, input())) for _ in range(N))
visit = [[0]*N for _ in range(N)]
A, B = 0, 0
def BFS(X, Y):
    currentColor = MATRIX[X][Y]
    Q = deque()
    Q.append((X, Y))
    visit[X][Y] = 1
    while Q:
        x, y = Q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < N and 0 <= ny < N and visit[nx][ny] == 0 and MATRIX[nx][ny] == currentColor:
                visit[nx][ny] = 1
                Q.append((nx, ny))

for i in range(N):
    for j in range(N):
        if visit[i][j] == 0:
            BFS(i, j)
            A += 1

for i in range(N):
    for j in range(N):
        if MATRIX[i][j] == 'G':
            MATRIX[i][j] = 'R'

visit = [[0]*N for _ in range(N)]

for i in range(N):
    for j in range(N):
        if visit[i][j] == 0:
            BFS(i, j)
            B += 1

print("{} {}".format(A, B))
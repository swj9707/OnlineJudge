import sys ; input = lambda : sys.stdin.readline().rstrip()
from collections import deque

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def BFS(X, Y, safeArea):
    Q = deque()
    Q.append((X, Y))
    visit[X][Y] = True
    while(Q):
        x, y = Q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if 0 <= nx < N and 0 <= ny < N and visit[nx][ny] == False and matrix[nx][ny] >= safeArea:
                visit[nx][ny] = True
                Q.append((nx, ny))

N = int(input())
matrix = [list(map(int, input().split())) for i in range(N)]
minValue = min(map(min, matrix))
maxValue = max(map(max, matrix))

safeArea_Max = minValue

for safeArea in range(minValue, maxValue+1):
    tmp = 0
    visit = [[False]*N for i in range(N)]
    for i in range(N):
        for j in range(N):
            if matrix[i][j] >= safeArea and visit[i][j] == False:
                BFS(i, j, safeArea)
                tmp += 1
    if tmp > safeArea_Max:
        safeArea_Max = tmp
print(safeArea_Max)
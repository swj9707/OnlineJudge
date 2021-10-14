from collections import deque
import sys ; input = lambda : sys.stdin.readline().rstrip()
dx = [-1, -2, -2, -1, 1, 2, 2, 1]
dy = [2, 1, -1, -2, -2, -1, 1, 2]
def bfs(srcx, srcy, destx, desty):
    q = deque()
    q.append([srcx, srcy])
    s[srcx][srcy] = 1
    while q:
        a, b = q.popleft()
        if a == destx and b == desty:
            print(s[destx][desty] -1)
            return
        for i in range(8):
            x = a + dx[i]
            y = b + dy[i]
            if 0 <= x < n and 0 <= y < n and s[x][y] == 0:
                q.append([x, y])
                s[x][y] = s[a][b] + 1
t = int(input())
for i in range(t):
    n = int(input())
    srcx, srcy = map(int, input().split())
    destx, desty = map(int, input().split())
    s = [[0] * n for i in range(n)]
    bfs(srcx, srcy, destx, desty)
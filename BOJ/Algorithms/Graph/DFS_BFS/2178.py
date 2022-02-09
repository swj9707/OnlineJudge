import sys ; input = lambda : sys.stdin.readline().rstrip()

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
def BFS(board, N, M):
    board[0][0] = 1
    queue = [[0,0]]
    while queue:
        X, Y = queue[0][0], queue[0][1]
        del queue[0]
        for i in range(4):
            nx = X + dx[i]
            ny = Y + dy[i]
            if(nx >= 0 and ny >= 0 and nx < N and ny < M):
                if board[nx][ny] == '1':
                    queue.append([nx, ny])
                    board[nx][ny] = board[X][Y] + 1

N, M = map(int, input().split())

board = [list(input()) for _ in range(N)]

BFS(board, N, M)
print(board[N-1][M-1])
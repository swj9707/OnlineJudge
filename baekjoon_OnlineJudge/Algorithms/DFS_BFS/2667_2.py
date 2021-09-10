import sys ; input = lambda : sys.stdin.readline().rstrip()

N = int(input())

apt_map = [list(map(int, input())) for _ in range(N)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

apt_map[0][0] = 1
queue = [[0,0]]
def bfs(queue, board):
    global count
    while queue:
        x, y = queue[0][0], queue[0][1]
        del queue[0]
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx >= 0 and ny >= 0 and nx < N and ny < N:
                if board[nx][ny] == 1:
                    queue.append([nx, ny])
                    board[nx][ny] = board[x][y] + 1

bfs(queue, apt_map)
print(len(queue))

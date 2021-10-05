import sys ; input = lambda : sys.stdin.readline().rstrip()
N, M = map(int, input().split())
data = [list(map(int, input().split())) for i in range(N)]
answer = 0
tetromino = [
    [(0,0), (0,1), (1,0), (1,1)], # case ��
    [(0,0), (0,1), (0,2), (0,3)], # case ��
    [(0,0), (1,0), (2,0), (3,0)], # case ��
    [(0,0), (0,1), (0,2), (1,0)], 
    [(1,0), (1,1), (1,2), (0,2)],
    [(0,0), (1,0), (1,1), (1,2)], # case ��
    [(0,0), (0,1), (0,2), (1,2)], # case ��
    [(0,0), (1,0), (2,0), (2,1)],
    [(2,0), (2,1), (1,1), (0,1)],
    [(0,0), (0,1), (1,0), (2,0)], 
    [(0,0), (0,1), (1,1), (2,1)],
    [(0,0), (0,1), (0,2), (1,1)], # case ��
    [(1,0), (1,1), (1,2), (0,1)], # case ��
    [(0,0), (1,0), (2,0), (1,1)], # case ��
    [(1,0), (0,1), (1,1), (2,1)], # case ��
    [(1,0), (2,0), (0,1), (1,1)],
    [(0,0), (1,0), (1,1), (2,1)],
    [(1,0), (0,1), (1,1), (0,2)],
    [(0,0), (0,1), (1,1), (1,2)]
]

for i in range(N):
    for j in range(M):
        for k in range(19):
            result = 0
            x = i
            y = j
            for L in range(4):
                try:
                    X = x + tetromino[i][j][0]
                    Y = y + tetromino[i][j][1]
                    result += board[X][Y]
                except Exception:
                    continue
            answer = max(answer, result)

print(answer)

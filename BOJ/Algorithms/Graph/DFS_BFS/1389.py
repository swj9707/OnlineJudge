import sys; input = lambda : sys.stdin.readline().rstrip()

def FloydWarshall():
    for k in range(1, N+1):
        for i in range(1, N+1):
            for j in range(1, N+1):
                if i == j:
                    continue
                elif MATRIX[i][k] != 0 and MATRIX[k][j] != 0:
                    if MATRIX[i][j] == 0:
                        MATRIX[i][j] = MATRIX[i][k] + MATRIX[k][j]
                    else:
                        MATRIX[i][j] = min(MATRIX[i][j],MATRIX[i][k] + MATRIX[k][j])

N, M = map(int, input().split())

MATRIX = [[0 for _ in range(N+1)] for _ in range(N+1)]
for i in range(M):
    A, B = map(int, input().split())
    MATRIX[A][B] = MATRIX[B][A] = 1
FloydWarshall()
answer = 1
result = 99999999
for i in range(1, N+1):
    tmpResult = 0
    for j in range(1, N+1):
        tmpResult += MATRIX[i][j]
    if result > tmpResult:
        result = tmpResult
        answer = i
print(answer)
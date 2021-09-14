import sys ; input = lambda : sys.stdin.readline().rstrip()

N, M = map(int, input().split())

matrixA = [list(map(int, input())) for i in range(N)]
matrixB = [list(map(int, input())) for i in range(N)]

print(matrixA)
print("")
print(matrixB)
def changeData(x, y, arr):
    for i in range(x, x+3):
        for j in range(y, y+3):
            arr[i][j] = 1 - arr[i][j]

answer = 0
for i in range(0, N-2):
    for j in range(0, M-2):
        if matrixA[i][j] != matrixB[i][j]:
            changeData(i,j,matrixA)
            answer += 1

print(matrixA)
print("")
print(matrixB)

if matrixA != matrixB:
    print(-1)
else:
    print(answer)

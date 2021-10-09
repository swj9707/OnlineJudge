import sys ; input = lambda : sys.stdin.readline().rstrip()
from collections import deque

matrix = [[0] * 101 for i in range(101)]
visitList = [False] * 101

def BFS(N : int, A : int) -> int:
    Q = deque()
    result = 0
    Q.append(A)
    visitList[A] = True
    while(Q):
        A = Q.popleft()
        for i in range(1, N+1):
             if matrix[A][i] == 1 and visitList[i] == False:
                visitList[i] = True
                Q.append(i)
                result += 1
    return result

N = int(input())
M = int(input())
for i in range(M):
    A, B = map(int, input().split())
    matrix[A][B] = matrix[B][A] = 1
Answer = BFS(N, 1)
print(Answer)

import sys ; input = lambda : sys.stdin.readline().rstrip()

N, M = map(int, input().split())
matrix=[[0]*(N+1) for i in range(N+1)]
for _ in range(M):
    u, v = map(int, input().split())
    matrix[u][v] = matrix[v][u] = 1
visit_list = [0] * (N+1)

def 
    


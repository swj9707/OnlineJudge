import sys ; input = lambda : sys.stdin.readline().rstrip()

N, M = map(int, input().split())
matrix=[[0]*(N+1) for i in range(N+1)]
for _ in range(M):
    u, v = map(int, input().split())
    matrix[u][v] = matrix[v][u] = 1
visit_list = [0] * (N+1)

count = 0

def dfs(V):
    visit_list[V] = 1
    for i in range(1, N+1):
        if(visit_list[i] == 0 and matrix[V][i]==1):
            dfs(i)


for i in range(1, N+1):
    if not visit_list[i]:
        dfs(i)
        count += 1

print(count)

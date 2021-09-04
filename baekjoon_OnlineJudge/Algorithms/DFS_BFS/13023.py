import sys ; input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(10**6)

N, M = map(int, input().split())

matrix = [[0] * (N+1) for i in range(N+1)]
visit_list = [0]*(N+1)

for _ in range(M):
    a, b = map(int, input().split())
    matrix[a][b] = matrix[b][a] = 1

depth = 0
def dfs(V):
    global depth
    if depth == 5:
        print(1)
        exit()
    visit_list[V] = 1
    depth += 1
    for i in range(1, N+1):
        if(visit_list[i] == 0 and matrix[V][i]==1):
            dfs(i)
          
dfs(0)
print(0)

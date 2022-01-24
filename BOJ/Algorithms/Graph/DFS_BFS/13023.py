import sys ; input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(10**6)

N, M = map(int, input().split())

graph = [[] for i in range(N+1)]
visit = [False for i in range(N+1)]

visit[0] = True

def dfs(V, depth):
    visit[V] = True
    if depth >= 4:
        print(1)
        exit()
    for i in graph[V]:
        if visit[i] == False:
            dfs(i, depth+1)
            visit[i] = False

for i in range(M):
    a, b = map(int, input().split())
    graph[a+1].append(b+1)
    graph[b+1].append(a+1)

for i in range(1, N+1):
    dfs(i, 0)
    visit[i] = False
print(0)

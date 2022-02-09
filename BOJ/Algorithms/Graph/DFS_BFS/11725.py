import sys ; input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(10**6)
def DFS(V):
    visit[V] = True
    for i in range(len(Tree[V])):
        next = Tree[V][i]
        if visit[next] == 0:
            parent[next] = V
            DFS(next)

N = int(input())

Tree = [[] for _ in range(N+1)]
visit = [0 for _ in range(N+1)]
parent = [0 for _ in range(N+1)]

for i in range(N-1):
    A, B = map(int, input().split())
    Tree[A].append(B)
    Tree[B].append(A)

DFS(1)
for i in range(2, N+1):
    print(parent[i])
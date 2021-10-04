N,M,V=map(int,input().split())
matrix=[[0]*(N+1) for i in range(N+1)]
for i in range(M):
    a,b = map(int,input().split())
    matrix[a][b]=matrix[b][a]=1#a번 노드에 대해서 a-b관계, b번 노드에 대해서 b-a 관계 입력
visit_list=[0]*(N+1)

def dfs(V):
    visit_list[V]=1#방문한 위치에 1 마킹
    print(V, end=' ')#출력
    for i in range(1,N+1):#쭉 돌아보면서
        if(visit_list[i]==0 and matrix[V][i]==1):#만약 방문하지 않았고 그 쪽에 경로가 있다면
            dfs(i)#탐색 

def bfs(V):
    queue=[V] 
    visit_list[V]=0 
    while queue:
        V=queue.pop(0)
        print(V, end=' ')
        for i in range(1, N+1):
            if(visit_list[i]==1 and matrix[V][i]==1):
                queue.append(i)
                visit_list[i]=0

dfs(V)
print()
bfs(V)
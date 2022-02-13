def BFS(n, adjMatrix, node):
    from collections import deque
    maxLength = 0
    Q = deque()
    Q.append(1)
    while Q:
        current = Q.popleft()
        for i in range(len(adjMatrix[current])):
            if node[adjMatrix[current][i]] == 0 and adjMatrix[current][i] != 1:
                node[adjMatrix[current][i]] = node[current] + 1
                Q.append(adjMatrix[current][i])
                maxLength = max(maxLength, node[adjMatrix[current][i]])
    return maxLength

def solution(n, edge):
    answer = 0
    adjMatrix = [[] for _ in range(n+1)]
    node = [0] * (n+1)    
    for i in edge:
        src, dst = i[0], i[1]
        adjMatrix[src].append(dst)
        adjMatrix[dst].append(src)
    maxLength = BFS(n, adjMatrix, node)
    for i in range(1, n+1):
        if maxLength == node[i]:
            answer += 1

    return answer
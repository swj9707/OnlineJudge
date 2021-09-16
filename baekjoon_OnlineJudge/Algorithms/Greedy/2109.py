import sys ; input = lambda : sys.stdin.readline().rstrip()
import heapq

N = int(input())

data = [list(map(int, input().split())) for _ in range(N)]
data = sorted(data, key = lambda x : x[1])

pList = []
for i in data:
    heapq.heappush(pList, i[0])
    if len(pList) > i[1]:
        heapq.heappop(pList)
print(sum(pList))


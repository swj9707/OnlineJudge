import sys ; input = lambda : sys.stdin.readline().rstrip()

N, M = map(int, input().split())

arr = []
maxSet = set()

for i in range(N):
    row = list(map(int, input().split()))
    maxSet.add(max(row))
    arr.append(row)

for j in range(M):
    maxSet.add(max(arr[i][j] for i in range(N)))

print(sum(map(sum, arr)) - sum(maxSet))
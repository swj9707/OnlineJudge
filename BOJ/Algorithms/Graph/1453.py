import sys; input = lambda : sys.stdin.readline().rstrip()

N = int(input())
dataList = list(map(int, input().split()))
seat = [0] * (N+1)
for i in dataList:
    if seat[i] == 0:
        seat[i] = 1

answer = sum(seat) - N
print(answer)
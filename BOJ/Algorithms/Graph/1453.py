import sys; input = lambda : sys.stdin.readline().rstrip()

N = int(input())
dataList = list(map(int, input().split()))
seat = [0] * 101
for i in dataList:
    if seat[i] == 0:
        seat[i] = 1

answer = N - sum(seat)
print(answer)
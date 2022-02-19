import sys ; input = lambda : sys.stdin.readline().rstrip()

N = int(input())
dataList = sorted(list(map(int, input().split())))
answer = 987654321
for i in range(len(dataList)):
    answer = min(answer, dataList[i] + dataList[len(dataList) - i - 1])
print(answer)
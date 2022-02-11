import sys ; input = lambda : sys.stdin.readline().rstrip()

N = int(input())
dataList = sorted(list(map(int, input().split())), reverse=True)
maxValue = dataList[0]
answer = sum(list(dataList[i] + maxValue for i in range(1, len(dataList))))
print(answer)
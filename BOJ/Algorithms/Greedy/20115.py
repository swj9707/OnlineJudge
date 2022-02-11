import sys ; input = lambda : sys.stdin.readline().rstrip()

N = int(input())
dataList = sorted(list(map(int, input().split())), reverse=True)
answer = dataList[0] + sum(list(dataList[i] / 2 for i in range(1, len(dataList))))
print("%g"%answer)
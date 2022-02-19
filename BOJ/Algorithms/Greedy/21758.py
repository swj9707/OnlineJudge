from copy import deepcopy
import sys ; input = lambda : sys.stdin.readline().rstrip()

N = int(input())
dataList = list(map(int, input().split()))
sumofData = deepcopy(dataList)
answer = 0
for i in range(1, N):
    sumofData[i] += sumofData[i-1]

for i in range(1, N-1):
    answer = max(answer, 2*sumofData[-1]-dataList[0]-dataList[i]-sumofData[i])
for i in range(1, N-1):
    answer = max(answer, sumofData[-1]-dataList[-1]-dataList[i]+sumofData[i-1])
for i in range(1, N-1): 
    answer = max(answer, sumofData[i]-dataList[0] + sumofData[-1]-sumofData[i-1]-dataList[-1])

print(answer)
import sys

input = lambda : sys.stdin.readline().rstrip()

M = int(input())
N = int(input())

dataList = []

i = 1

while i ** 2 <= N:
    if i ** 2 >= M and i ** 2 <= N:
        dataList.append(i**2)
    i += 1

if len(dataList) < 1:
    print('-1')
else:
    print(sum(dataList))
    print(dataList[0])

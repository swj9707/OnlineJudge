import sys; input = lambda : sys.stdin.readline().rstrip()
dataList = list(map(int, input().split()))

if dataList == sorted(dataList):
    print('ascending')
elif dataList == sorted(dataList, reverse=True):
    print('descending')
else:
    print('mixed')
import sys; input = lambda : sys.stdin.readline().rstrip()
import itertools
arr1 = list(list(map(int, input().split())) for _ in range(5))
indexList = dict()
for i in range(5):
    for j in range(5):
        indexList[arr1[i][j]] = (i, j)
'''
for i in indexList:
    print(indexList[i])
'''
arr2 = list(map(int, input().split()) for _ in range(5))
arr2 = list(itertools.chain(*arr2))

for idx in range(len(arr2)):
    X, Y = indexList[arr2[idx]]
    arr1[X][Y] = -1
    for i in range(5):
        if str(arr1[i]).count('[-1,-1,-1,-1,-1')
import sys ; input = lambda : sys.stdin.readline().rstrip()
import itertools

N = int(input())
inputData = tuple(map(int, input().split()))
data = [i for i in range(1, N+1)]
combi = itertools.permutations(data, N)
flag = 0
for i in combi:
    if flag == 1:
        print(i)
        break
    if inputData == i:
        flag = 1

import sys ; input = lambda : sys.stdin.readline().rstrip()

N = int(input())
pointList = list(map(int, input().split()))
rangeList = list(map(int, input().split()))

if N != 1:
    maxRange = 0
    for i in range(N-1):
        maxRange = max(maxRange, pointList[i] + rangeList[i])
        if maxRange >= pointList[i+1]:
            continue
        else:
            print("엄마 나 전역 늦어질 것 같아")
            exit()
print("권병장님, 중대장님이 찾으십니다")
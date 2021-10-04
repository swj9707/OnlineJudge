import sys

input = lambda : sys.stdin.readline().rstrip()

while True:
    data = list(map(int, input().split()))
    maxNum = max(data)
    if sum(data) == 0:
        break
    data.remove(maxNum)
    if data[0] ** 2 + data[1] ** 2 == maxNum ** 2:
        print('right')
    else:
        print('wrong')

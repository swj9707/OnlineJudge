import sys ; input = lambda : sys.stdin.readline().rstrip()

N = int(input())
arr = sorted(list(map(int, input().split())))
maxData = arr[-1]
answer = 0
if len(arr) % 2 == 0:
    while arr:
        tmp = arr[0] + arr[-1]
        arr.pop(0)
        arr.pop(-1)
        answer = max(answer, tmp)
else:
    answer = maxData
    arr.pop()
    while arr:
        tmp = arr[0] + arr[-1]
        arr.pop(0)
        arr.pop(-1)
        answer = max(answer, tmp)
print(answer)
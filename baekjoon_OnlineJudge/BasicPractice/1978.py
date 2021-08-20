import sys
input = lambda : sys.stdin.readline().rstrip()

N = int(input())
data = list(map(int, input().split()))
result = 0
for i in data:
    if i == 1:
        result += 1
    else:
        for j in (1, i // 2):
            if i % j == 0:
                result += 1
                break
print(result)
import sys; input = lambda : sys.stdin.readline().rstrip()

N, A, D = map(int, input().split())
Arr = list(map(int, input().split()))
answer = 0
cmp = A
for i in Arr:
    if i == cmp:
        cmp += D
        answer += 1
print(answer)
import sys ; input = lambda : sys.stdin.readline().rstrip()

n = int(input())
v = list(map(int, input().split()))
answer = 0
for i in range(n-1, -1, -1):
    if answer <= v[i]:
        answer = v[i]
    else:
        if answer % v[i]:
            answer = (answer // v[i] + 1) * v[i]
    print(answer, v[i])
print(answer)
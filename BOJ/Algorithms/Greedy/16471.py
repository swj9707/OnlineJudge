import sys ; input = lambda : sys.stdin.readline().rstrip()

N = int(input())
userData = sorted(list(map(int, input().split())))
masterData = sorted(list(map(int, input().split())))

idx1 = 0
idx2 = 0
score = 0
win = (N + 1) / 2

while True:
    if userData[idx1] < masterData[idx2]:
        score += 1
        idx1 +=1
        idx2 +=1
    else:
        idx2 += 1
    if idx2 == N:
        break

if score >= win:
    print("YES")
else:
    print("NO")


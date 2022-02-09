import sys ; input = lambda : sys.stdin.readline().rstrip()

T = int(input())

while T > 0:
    N = int(input())
    answer = 0
    for i in range(1, N):
        if i ** 2 <= N:
            answer +=1
        else:
            break
    print(answer)
    T -=1
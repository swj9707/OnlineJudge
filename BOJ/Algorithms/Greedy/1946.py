import sys; input = lambda : sys.stdin.readline().rstrip()
T = int(input())
while(T>0):
    N = int(input())
    data = sorted([list(map(int, input().split())) for i in range(N)], key = lambda x : x[0])
    count = 1
    min = data[0][1]

    for i in range(1, N):
        if data[i][1] < min:
            min = data[i][1]
            count += 1
    print(count)
    T -= 1
import sys

C = int(sys.stdin.readline().rstrip())

for _ in range(C):
    case = list(map(int, sys.stdin.readline().rstrip().split()))
    total = sum(case[1:])
    N = case[0]
    Avg = total / N
    count = 0

    for i in range(1, N + 1):
        if case[i] > Avg:
            count += 1
    rate = (count/N)*100
    print(f'{rate:.3f}%')



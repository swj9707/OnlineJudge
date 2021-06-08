import sys

N = int(sys.stdin.readline().rstrip())

for i in range(1, N + 1):
    A = list(map(int,str(i)))
    result = i + sum(A)
    if result == N:
        print(i)
        break

    if i == N:
        print(0)

import sys ; input = lambda : sys.stdin.readline().rstrip()

T = int(input())

for _ in range(T):
    data = input()
    print(data[0], end='')
    print(data[-1])
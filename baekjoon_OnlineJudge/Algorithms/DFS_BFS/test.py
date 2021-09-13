import sys ; input = lambda : sys.stdin.readline().rstrip()

N, M = map(int, input().split())

data = [list(map(int, input())) for i in range(M)]
print(data)
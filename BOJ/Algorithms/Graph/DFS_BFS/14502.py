import sys ; input = lambda : sys.stdin.readline().rstrip()

N, M = map(int, input().split())
MATRIX = [list(map(int, input().split())) for _ in range(N)]
print(MATRIX)
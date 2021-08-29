import sys ; input = lambda : sys.stdin.readline().rstrip()
W = sorted([int(input())for _ in range(10)])[7:]
K = sorted([int(input())for _ in range(10)])[7:]
print(sum(W), sum(K))

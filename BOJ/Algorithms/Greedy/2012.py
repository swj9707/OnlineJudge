import sys ; input = lambda : sys.stdin.readline().rstrip()

N = int(input())
data = sorted(list(int(input()) for _ in range(N)))
answer = sum(abs((i+1 - data[i])) for i in range(N))
print(answer)

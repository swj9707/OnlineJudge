import sys ; input = lambda : sys.stdin.readline().rstrip()

answer = 0
for _ in range(int(input())):
    A, B = map(int, input().split())
    answer += B % A

print(answer)
    
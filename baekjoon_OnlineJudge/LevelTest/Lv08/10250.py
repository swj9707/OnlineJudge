import sys

input = lambda : sys.stdin.readline().rstrip()

T = int(input())

for i in range(T):
    H, W, N = map(int, input().split())
    num = 1 + (N // H)
    Height = N % H
    numDigit = len(str(W))
    num = str(num).zfill(numDigit)
    answer = str(Height) + num
    print(answer)


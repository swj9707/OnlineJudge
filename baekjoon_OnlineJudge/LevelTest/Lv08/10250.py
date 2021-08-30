import sys

input = lambda : sys.stdin.readline().rstrip()

T = int(input())

for i in range(T):
    H, W, N = map(int, input().split())
    num = 1 + (N // H)
    Height = N % H
    if Height == 0:
        Height = H; num -= 1
    print(100*Height+num)


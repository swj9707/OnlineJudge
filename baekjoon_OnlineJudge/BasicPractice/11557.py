import sys
input = lambda : sys.stdin.readline().rstrip()

T = int(input())

for _ in range(T):
    N = int(input())
    uni = ''
    maxValue = 0
    for i in range(N):
        A, B = map(str, input().split())
        if maxValue < int(B):
            maxValue = int(B)
            uni = A
    print(uni)

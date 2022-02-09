import sys; input = lambda : sys.stdin.readline().rstrip()

A = sum(list(map(int, input().split())))
B = sum(list(map(int, input().split())))
if A > B:
    print(A)
else:
    print(B)
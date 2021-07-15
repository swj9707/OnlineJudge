import sys
input = lambda : sys.stdin.readline().rstrip()

n = int(input())
for _ in range(n):
    p = int(input())
    max = 0
    name = ''
    for i in range(p):
        A, B = map(str, input().split())
        if max < int(A):
            max = int(A)
            name = B
    print(name)

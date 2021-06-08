import sys

A, B = map(str, sys.stdin.readline().rstrip().split())

A1 = A[::-1]
B1 = B[::-1]

if int(A1) > int(B1):
    print(A1)
else:
    print(B1)

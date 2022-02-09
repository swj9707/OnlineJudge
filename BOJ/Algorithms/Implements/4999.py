import sys ; input = lambda : sys.stdin.readline().rstrip()

A = input()
B = input()

if len(A) >= len(B):
    print("go")
else:
    print("no")
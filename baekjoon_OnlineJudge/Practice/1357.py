import sys
input = lambda : sys.stdin.readline().rstrip()

def Rev(x):
    return int(str(x)[::-1])

X, Y = map(int, input().split())
Z = Rev(X) + Rev(Y)
print(Rev(Z))

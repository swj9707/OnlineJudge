import sys

N = int(sys.stdin.readline().rstrip())

a = list(map(int, sys.stdin.readline().rstrip().split()))
a.sort()
x = len(a)

print(a[0]+' '+a[x-1])
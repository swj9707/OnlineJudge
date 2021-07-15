import sys
input = lambda : sys.stdin.readline().rstrip()

N = input()

data = [int(i) for i in N]
data = sorted(data, reverse=True)

for i in data:
    print(i, end="")

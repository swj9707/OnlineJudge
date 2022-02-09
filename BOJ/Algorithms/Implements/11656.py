import sys; input = lambda : sys.stdin.readline().rstrip()

S = input()
N = len(S)
data = sorted([S[i:N] for i in range(N)])
for i in data:
    print (i)
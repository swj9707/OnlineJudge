import sys ; input = lambda : sys.stdin.readline().rstrip()

n = list(input())
n.sort(reverse=True)
sum = sum(int(i) for i in n)
if sum % 3 != 0 or "0" not in n:
    print(-1)
else:
    print(''.join(n))
import sys
input = lambda : sys.stdin.readline().rstrip()

N = int(input())

for _ in range(N):
    r, e, c = map(int, input().split())
    delta = e - c
    if delta > r:
        print('advertise')
    elif delta == r:
        print('does not matter')
    else:
        print('do not advertise')
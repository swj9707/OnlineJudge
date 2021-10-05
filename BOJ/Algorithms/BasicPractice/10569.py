import sys
input = lambda : sys.stdin.readline().rstrip()

T = int(input())

for _ in range(T):
    V, E = map(int, input().split())
    print(2 + E - V)

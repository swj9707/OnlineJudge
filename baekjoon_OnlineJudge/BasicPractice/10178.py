import sys
input = lambda : sys.stdin.readline().rstrip()

T = int(input())

for _ in range(T):
    c, v = map(int, input().split())
    print("You get %d piece(s) and your dad gets %d piece(s)." %(c//v, c%v))
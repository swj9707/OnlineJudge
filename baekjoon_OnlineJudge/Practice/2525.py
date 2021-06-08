import sys
input = lambda : sys.stdin.readline().rstrip()

A, B = map(int, input())
C = int(input())
D = C / 60
E = C % 60

A = A + D
B = B + E
F = B / 60
G = B % 60
A = A + F
B = B % 60
if A >

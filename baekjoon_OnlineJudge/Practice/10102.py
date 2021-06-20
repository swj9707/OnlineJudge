import sys
input = lambda : sys.stdin.readline().rstrip()

V = int(input())
data = input()
A = 0
B = 0
for i in range(V):
    if data[i] == 'A':
        A += 1
    else:
        B += 1

if A > B:
    print('A')
elif A < B:
    print('B')
else:
    print('Tie')

import sys
input = lambda : sys.stdin.readline().rstrip()

N = input()

if 'A' in N:
    if N == 'A+':
        print(4.3)
    elif N == 'A0':
        print(4.0)
    elif N == 'A-':
        print(3.7)
elif 'B' in N:
    if N == 'B+':
        print(3.3)
    elif N == 'B0':
        print(3.0)
    elif N == 'B-':
        print(2.7)
elif 'C' in N:
    if N == 'C+':
        print(2.3)
    elif N == 'C0':
        print(2.0)
    elif N == 'C-':
        print(1.7)
elif 'D' in N:
    if N == 'D+':
        print(1.3)
    elif N == 'D0':
        print(1.0)
    elif N == 'D-':
        print(0.7)
else:
    print(0.0)
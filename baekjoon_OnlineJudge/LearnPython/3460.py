import sys

input = lambda : sys.stdin.readline().rstrip()

T = int(input())

for i in range(T):
    N = int(input())
    N_B = format(N, 'b')
    data = []
    for i in range(len(N_B)):
        if N_B[-i-1] == '1':
            data.append(str(i))
    answer = ' '.join(data)
    print(answer)

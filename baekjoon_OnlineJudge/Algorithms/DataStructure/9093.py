import sys ; input = lambda : sys.stdin.readline().rstrip()

T = int(input())

for _ in range(T):
    data = list(map(str, input().split()))
    for i in data:
        i_list = list(i)
        i_list.reverse()
        print(''.join(i_list), end=' ')
    print()
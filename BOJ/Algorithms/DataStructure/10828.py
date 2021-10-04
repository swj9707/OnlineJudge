import sys ; input = lambda : sys.stdin.readline().rstrip()

stack = []

N = int(input())

for _ in range(N):
    data = input().split()

    if data[0] == 'push':
        stack.append(data[1])
    elif data[0] == 'pop':
        if len(stack) == 0:
            print(-1)
        else:
            print(stack.pop())
    elif data[0] == 'size':
        print(len(stack))
    elif data[0] == 'empty':
        if len(stack) == 0:
            print(1)
        else:
            print(0)
    elif data[0] == 'top':
        if len(stack) == 0:
            print(-1)
        else:
            print(stack[-1])

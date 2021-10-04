import sys
input = lambda : sys.stdin.readline().rstrip()

def fib(n):
    curr, next = 0, 1
    for _ in range(n):
        curr, next = next, curr + next
    return ccurr

n = int(input())
print(fib(n))

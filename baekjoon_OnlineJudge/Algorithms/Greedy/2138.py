import sys ; input = lambda : sys.stdin.readline().rstrip()

N = int(input())

def chgLights(A):
    if A == '0':
        A = '1'
    else:
        A = '0'

def chgSwitch(lights, N):
    if N == 0:
        lights[N] = 1 - lights[N]
        lights[N + 1] = 1 - lights[N+1]
    elif N == len(lights):
        lights[len(lights)] = 1 - lights[len(lights)]
        lights[len(lights) - 1] = 1 - lights[len(lights) - 1]
    else:
        lights[N-1] = 1 - lights[N-1]
        lights[N] = 1 - lights[N]
        lights[N + 1] = 1 - lights[N+1]

now = input()
answer = input()



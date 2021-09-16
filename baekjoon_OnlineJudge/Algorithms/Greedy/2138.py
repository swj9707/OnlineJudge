import sys ; input = lambda : sys.stdin.readline().rstrip()

N = int(input())

def chgLights(A):
    if A == '0':
        A = '1'
    else:
        A = '0'
    return A

def chgSwitch(lights, N):
    if N == 0:
        Lights[N] = chgLights(lights[N])
        Lights[N+1] = chgLights(lights[N + 1])
    elif N == len(lights):
        Lights[len(lights)] = chgLights(lights[len(lights)])
        Lights[len(lights)-1] = chgLights(lights[len(lights) - 1])
    else:
        Lights[N-1] = chgLights(lights[N-1])
        Lights[N] = chgLights(lights[N])
        Lights[N+1] = chgLights(lights[N + 1])

now = input()
answer = input()



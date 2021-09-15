import sys ; input = lambda : sys.stdin.readline().rstrip()

N = int(input())

def chgLights(A):
    if A == '0':
        A = '1'
    else:
        A = '0'

def chgSwitch(lights, N):
    if N == 0:
        chgLights(lightss[N])
        chgLights(lights[N + 1])
    elif N == len(lights):
        chgLights(lights[len(lights)])
        chgLights(lights[len(lights) - 1])
    else:
        chgLights(lights[N-1])
        chgLights(lightss[N])
        chgLights(lights[N + 1])

now = input()
answer = input()



import sys ; input = lambda : sys.stdin.readline().rstrip()

N = int(input())

def chgLight(lights, N):
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



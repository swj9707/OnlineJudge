import sys ; input = lambda : sys.stdin.readline().rstrip()

N = int(input())

def chgLight(value):
    if value == '0':
        return '1'
    else:
        return '0'


def chgSwitch(Lights, N):
    if N == 0:
        Lights[N] = chgLight(Lights[N])
        Lights[N+1] = chgLight(Lights[N + 1])
    elif N == (len(Lights) - 1):
        Lights[N] = chgLight(Lights[N])
        Lights[N-1] = chgLight(Lights[N - 1])
    else:
        Lights[N-1] = chgLight(Lights[N-1])
        Lights[N] = chgLight(Lights[N])
        Lights[N+1] = chgLight(Lights[N + 1])

now = list(input())
answer = list(input())

def first(Lights):
    count = 1
    chgSwitch(Lights, 0)
    for i in range(1, len(Lights)):
        if Lights[i- 1] == answer[i-1]:
            continue
        else:
            count += 1
            chgSwitch(Lights, i)
    if Lights == answer:
        return count
    return 999999

def second(Lights):
    count = 0
    for i in range(1, len(Lights)):
        if Lights[i- 1] == answer[i-1]:
            continue
        else:
            count += 1
            chgSwitch(Lights, i)
    if Lights == answer:
        return count
    return 999999

A = first(now[:])
B = second(now[:])

result = min(A,B)
if result == 999999:
    print(-1)
else:
    print(result)

import sys ; input = lambda : sys.stdin.readline().rstrip()

N = int(input())

def chgSwitch(Lights, N):
    if N == 0:
        Lights[N] = str(1 - int(Lights[N]))
        Lights[N+1] = str(1 - int(Lights[N + 1]))
    elif N == len(lights):
        Lights[len(lights)] = str(1 - int(Lights[len(Lights)]))
        Lights[len(lights)-1] = str(1 - int(Lights[len(Lights) - 1]))
    else:
        Lights[N-1] = str(1 - int(Lights[N-1]))
        Lights[N] = str(1 - int(Lights[N]))
        Lights[N+1] = str(1 - int(Lights[N + 1]))

now = input()
answer = input()

def first(Lights):
    count = 0
    chgSwitch(Lights, 0)
    for i in range(1, len(Lights)):
        if Lights[i- 1] == answer[i-1]:
            continue
        else:
            count += 1
            chgSwitch(Lights, i)
    if Lights == answer:
        return count
    return -1

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
    return -1

answer = min(first(now), second(now))
if answer == -1:
    print(-1)
else:
    print(answer)

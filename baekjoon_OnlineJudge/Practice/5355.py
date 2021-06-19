import sys
input = lambda : sys.stdin.readline().rstrip()

T = int(input())

for i in range(T):
    data = list(map(str, input().split()))
    answer = 0
    for j in range(len(data)):
        if j == 0:
            answer += float(data[j])
        else:
            if data[j] == '@':
                answer *= 3
            elif data[j] == '%':
                answer += 5
            elif data[j] == '#':
                answer -= 7

    print('%0.2f' % answer)



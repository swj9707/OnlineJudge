import sys

input = lambda : sys.stdin.readline().rstrip()

N = int(input())

answer = 0

for i in range(N):
    data = input()
    for j in range(len(data)):
        if j != len(data)-1:
            if data[j] == data[j+1]:
                pass
            elif data[j] in data[j+1:]:
                break
        else:
            answer += 1
print(answer)
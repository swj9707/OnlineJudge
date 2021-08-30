import sys
input = lambda : sys.stdin.readline().rstrip()

data = input()
answer = []

for i in data:
    if i.isupper() == True:
        answer.append(i.lower())
    else:
        answer.append(i.upper())

for i in answer:
    print(i, end='')

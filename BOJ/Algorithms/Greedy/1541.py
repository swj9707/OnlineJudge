import sys ; input = lambda : sys.stdin.readline().rstrip()

a = input().split('-')

data = []

for i in a:
    count = 0
    b = i.split('+')
    for c in b:
        count += int(c)
    data.append(count)

result = data[0]

for i in range(1, len(data)):
    result -= data[i]

print(result)

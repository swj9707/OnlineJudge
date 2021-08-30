import sys
input = lambda : sys.stdin.readline().rstrip()

data = []
odd = []
for i in range(7):
    data.append(int(input()))

for i in data:
    if i % 2 != 0:
        odd.append(i)

if len(odd) == 0:
    print(-1)
else:
    sum = 0
    odd.sort()
    for i in odd:
        sum += i
    print(sum)
    print(odd[0])

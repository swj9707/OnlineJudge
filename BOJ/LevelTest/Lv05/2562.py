import sys


case = []

for i in range(9):
    a = int(sys.stdin.readline().rstrip())
    case.append(a)
max = 0
index = 0
for i in range(9):
    if max < case[i]:
        max = case[i]
        index = i+1
print(max)
print(index)


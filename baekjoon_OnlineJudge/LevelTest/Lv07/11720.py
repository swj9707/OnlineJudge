import sys

A = int(sys.stdin.readline().rstrip())
B = list(sys.stdin.readline().rstrip())

sum = 0

for i in B:
    sum += int(i)
print(sum)

import sys

A = int(sys.stdin.readline().rstrip())
B = int(sys.stdin.readline().rstrip())
C = int(sys.stdin.readline().rstrip())

Result = A * B * C

result = [0,0,0,0,0,0,0,0,0,0]

while Result != 0:
    x = Result % 10
    result[x] += 1
    Result = Result // 10

for i in result:
    print(i)
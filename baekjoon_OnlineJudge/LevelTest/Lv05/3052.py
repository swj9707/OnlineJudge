import sys

case = []
for i in range(10):
    a = int(sys.stdin.readline().rstrip())
    case.append(a % 42)
case = set(case)
print(len(case))

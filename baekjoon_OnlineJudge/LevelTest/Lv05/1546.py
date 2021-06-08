import sys

N = int(sys.stdin.readline().rstrip())
case = list(map(int, sys.stdin.readline().rstrip().split()))
maxScore = max(case)
result = []
for i in case:
    result.append(i/maxScore*100)
result2 = sum(result)/N
print(result2)

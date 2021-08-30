import sys ; input = lambda : sys.stdin.readline().rstrip()
from math import gcd

T = int(input())
for _ in range(T):
    data = list(map(int, input().split()))
    a = data.pop(0)
    print(a)
    answer = 0
    for i in range(a):
        for j in range(a):
            if i < j:
                answer += gcd(data[i],data[j])
    print(answer)

import sys
input = lambda : sys.stdin.readline().rstrip()

N = int(input())

for _ in range(N):
    a = input()
    alphabetList = list(a)
    alphabetList = set(alphabetList)
    for i in a:



import sys ; input = lambda : sys.stdin.readline().rstrip()
from itertools import permutations

N = int(input())
K = int(input())
cards = [input() for _ in range(N)]
result = set()

for i in permutations(cards, K):
    result.add(''.join(i))
print(len(result))
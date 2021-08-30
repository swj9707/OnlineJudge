import sys
from math import gcd

input = lambda : sys.stdin.readline().rstrip()

def lcm(x, y):
    return x * y // gcd(x,y)

N = int(input())
data = list(map(int, input().split()))

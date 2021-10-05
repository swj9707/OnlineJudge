import sys

input = lambda : sys.stdin.readline().rstrip()

def gcd(a, b):
    return gcd(b, a % b) if b else a
def lcm(a, b):
    return a * b // gcd(a, b)

A, B = map(int, input().split())
print(gcd(A,B))
print(lcm(A,B))

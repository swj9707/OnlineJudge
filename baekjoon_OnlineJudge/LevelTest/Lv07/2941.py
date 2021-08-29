import sys

input = lambda : sys.stdin.readline().rstrip()

alphabet = ['c=','c-','dz=','d-','lj','nj','s=','z=']

X = input()

for i in alphabet:
    X = X.replace(i, '*')

print(len(X))

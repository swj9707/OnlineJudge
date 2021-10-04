import sys
input = lambda : sys.stdin.readline().rstrip()

data = input()

for i in range(0, len(data), 10):
    print(data[i:i+10])

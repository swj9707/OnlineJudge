import sys

input = lambda : sys.stdin.readline().rstrip()

Amount = int(input())
Amount = 1000 - Amount
data = [500,100,50,10,5,1]

result = 0

for i in data:
    result += Amount // i
    Amount = Amount % i

print(result)

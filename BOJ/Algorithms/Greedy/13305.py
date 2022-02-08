import sys; input = lambda : sys.stdin.readline().rstrip()

N = int(input())

dist = list(map(int,input().split()))
price = list(map(int,input().split()))

minVal = price[0]
sum = 0
for i in range(N-1):
    if minVal > price[i]:
        minVal = price[i]
    sum += (minVal * dist[i])
print(sum)
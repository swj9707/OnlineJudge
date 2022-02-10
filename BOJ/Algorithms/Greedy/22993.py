import sys; input = lambda : sys.stdin.readline().rstrip()

N = int(input())

data = list(map(int, input().split()))
jw = data[0]
data.pop(0)
data.sort()
for i in range(len(data)):
    if jw > data[i]:
        jw += data[i]
    else:
        print("No")
        exit()
print("Yes")

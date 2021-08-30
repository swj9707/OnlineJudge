import sys

input = lambda : sys.stdin.readline().rstrip()

data = []

for i in range(5):
    data.append(int(input()))

for i in range(5):
    if data[i] < 40:
        data[i] = 40

sum = data[0] + data[1] + data[2] + data[3] + data[4]
avg = int(sum / 5)

print(avg)

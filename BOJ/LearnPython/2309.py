import sys ; input = lambda : sys.stdin.readline().rstrip()
data = []
for _ in range(9):
    data.append(int(input()))
sum_Data = sum(data)
A = 0
B = 0
for i in range(8):
    for j in range(i+1, 9):
        if sum_Data - (data[i] + data[j]) == 100:
            A = data[i]
            B = data[j]
data.remove(A)
data.remove(B)
data.sort()
for i in data:
    print(i)

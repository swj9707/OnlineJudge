import sys

input = lambda : sys.stdin.readline().rstrip()

N = int(input())

data = []
alphabet = {}
num = 9
result = 0
for i in range(N):
    data.append(input())

data.sort(key=len, reverse=True)

for i in data:
    for j in i:
        if j not in alphabet:
            alphabet[j] = num
            print(j + ' ' + str(num))
            num -= 1

print(alphabet)

for i in data:
    digit = 10 ** (len(i)-1)
    for j in range(len(i)):
        result += alphabet[i[j]] * digit
        digit = digit // 10

print(result)
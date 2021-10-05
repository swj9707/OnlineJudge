import sys ; input = lambda : sys.stdin.readline().rstrip()

a = ['a','e','i','o','u']
data = input()
answer = 0
for i in range(len(data)):
    if data[i] in a: answer += 1
print(answer)
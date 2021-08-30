import sys ; input = lambda : sys.stdin.readline().rstrip()

a = input()

answer = [0] * 26

for i in a:
    answer[ord(i)-97] +=1
for i in answer:
    print(i, end=' ')
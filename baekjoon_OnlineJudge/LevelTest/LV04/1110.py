import sys

N = int(sys.stdin.readline().rstrip())
Answer = N
count = 0
while True:
    tmp = N // 10 + N % 10
    newNum= (num%10)*10 + tmp % 10
    count += 1
    N = newNum
    if newNum == Answer:
        break
print(count)

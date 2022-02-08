import sys; input = lambda : sys.stdin.readline().rstrip()

N = int(input())
A, B = map(int, input().split())
C = int(input())
topping = sorted(list(int(input()) for _ in range(N)), reverse=True)
sumOfCal = C
answer = C / A

for i in range(N):
    sumOfCal += topping[i]
    amount = A + B * (i+1)
    cal_per_amount = sumOfCal / amount
    answer = max(answer, cal_per_amount)

print(int(answer))
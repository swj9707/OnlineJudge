def solution(price, money, count):
    answer = -1
    Amount = 0
    for i in range(1, count+1):
        Amount += price * i
    if Amount - money > 0:
        answer = Amount - money
    else:
        answer = 0
    return answer
import sys

N = int(sys.stdin.readline().rstrip())

for i in range(N):
    case = list(sys.stdin.readline().rstrip())
    score = 0
    sumOfCorrect = 1
    for j in case:
        if j == 'O':
            score += sumOfCorrect
            sumOfCorrect += 1
        else:
            sumOfCorrect = 1
    print(score)
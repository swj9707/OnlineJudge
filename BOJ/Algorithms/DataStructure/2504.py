import sys ; input = lambda : sys.stdin.readline().rstrip();
str = input()
stk = []
stkIndex = 0
answer = 0
tmp = 1
for i in range(len(str)):
    if str[i] == '(':
        tmp *= 2
        stk.append(str[i])
        stkIndex += 1
    elif str[i] == '[':
        tmp *= 3
        stk.append(str[i])
        stkIndex += 1
    elif str[i] == ')':
        if len(stk) == 0 or stk[stkIndex-1] != '(':
            answer = 0
            break
        elif str[i-1] == '(':
            answer += tmp
            tmp /= 2
            stkIndex -= 1
        else:
            tmp /= 2
            stkIndex -= 1
    elif str[i] == ']':
        if len(stk) == 0 or stk[stkIndex-1] != '[':
            answer = 0
            break
        elif str[i-1] == '[':
            answer += tmp
            tmp /= 3
            stkIndex -= 1
        else:
            tmp /= 3
            stkIndex -= 1
if len(stk) != 0:
    answer = 0
print(answer)
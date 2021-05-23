import sys

dial = ['ABC','DEF','GHI','JKL','MNO','PGRS','TUV','WXYZ','OPERATION']

x = sys.stdin.readline().rstrip()

result = 0
for i in range(len(x)):
    for j in dial:
        if x[i] in j:
            result += dial.index(j)+3

print(result)

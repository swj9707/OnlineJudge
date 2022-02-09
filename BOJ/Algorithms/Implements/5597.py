import sys; input = lambda : sys.stdin.readline().rstrip()

students = [0 for i in range(31)]

for _ in range(28):
    students[int(input())] = 1
for _ in range(1, 31):
    if(students[_] == 0):
        print(_)
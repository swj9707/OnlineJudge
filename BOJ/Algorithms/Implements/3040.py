import sys ; input = lambda : sys.stdin.readline().rstrip()

li = sorted([int(input()) for _ in range(9)])
fin = 0
for i in range(8):
    if fin: 
        break
    for j in range(i+1, 9):
        if sum(li)-li[i]-li[j] == 100:
            li.pop(j); li.pop(i)
            fin = 1
            break
for n in li:
    print(n)
import sys ; input = lambda : sys.stdin.readline().rstrip()
count = 0
for _ in range(5):
    if('FBI' in input()):
        print(_+1, end=" ")
        count += 1
if count == 0:
    print("HE GOT AWAY!")

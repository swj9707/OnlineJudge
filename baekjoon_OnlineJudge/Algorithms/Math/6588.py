import sys ; input = lambda : sys.stdin.readline().rstrip()
r = 1000000

Prime = [True for i in range(r)]

for i in range(2, int(r**0.6)):
    if Prime[i] == True:
        for j in range(i*2, r, i):
            if Prime[j] == True:
                Prime[j] = False

while True:
    n = int(input())
    if n != 0:
        for i in range(3, r):
            if Prime[i] == True:
                if Prime[n-i] == True:
                    print("%d = %d + %d" %(n, i, n-i))
                    break
    else:
        break
import sys ; input = lambda : sys.stdin.readline().rstrip()

bulb = list(input())
bulb.insert(0, 'N')
count = 0
for i in range(1, len(bulb)):
    if i == 'Y':
        for j in range(i, len(bulb), i):
            if bulb[j] == 'Y':
                bulb[j] = 'N'
            else:
                bulb[j] = 'Y'
        count += 1
print(count)
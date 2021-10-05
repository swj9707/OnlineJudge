import sys

input = lambda :  sys.stdin.readline().rstrip()

K = int(input())

for _ in range(K):
    data = list(map(int, input().split()))
    data = data[1:]
    maxValue = max(data)
    minValue = min(data)
    data.sort(reverse=True)
    data2 = []
    for i in range(0, len(data) - 1):
        data2.append(data[i] -  data[i + 1])
    print('Class %d' % (_ + 1))
    print('Max %d, Min %d, Largest gap %d' % (maxValue, minValue, max(data2)))
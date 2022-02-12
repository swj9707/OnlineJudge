import sys; input = lambda : sys.stdin.readline().rstrip()

while True:
    dataList = list(map(str, input().split()))
    if dataList[0] == '0' and len(dataList) == 1:
        break
    dataList = sorted(dataList[1:])
    num_of_zero = dataList.count('0')
    dataList = dataList[num_of_zero:]
    first, second = '', ''
    first_zero, second_zero = 0, 0
    for i in range(len(dataList)):
        if i % 2 != 0: first += dataList[i]
        else : second += dataList[i]

    for i in range(num_of_zero):
        if len(first) == len(second):
            if i % 2 == 0 : first_zero += 1
            else: second_zero += 1
        else:
            if i % 2 == 0 : second_zero += 1
            else: first_zero += 1
    first = first[0] + '0' * first_zero + first[1:]
    second = second[0] + '0' * second_zero + second[1:]
    print(int(first) + int(second))
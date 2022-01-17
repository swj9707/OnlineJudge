def solution(progresses, speeds):
    answer = []
    tmp = []
    for i in range(len(progresses)):
        leftRate = 100 - progresses[i]
        date = leftRate // speeds[i]
        if leftRate % speeds[i] != 0:
            date += 1
        tmp.append(date)
    start = tmp[0]
    count = 0
    while len(tmp) > 0:
        if tmp[0] <= start:
            tmp.pop(0)
            count += 1
        else:
            if count > 0:
                start = tmp[0]
                answer.append(count)
                count = 0
    answer.append(count)
    return answer
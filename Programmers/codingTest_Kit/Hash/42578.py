def solution(clothes):
    answer = 1
    data = dict()
    for i in clothes:
        if i[1] in data:
            data[i[1]] += 1
        else:
            data[i[1]] = 1
    for i in data.values():
        answer *= (i+1)
    return answer
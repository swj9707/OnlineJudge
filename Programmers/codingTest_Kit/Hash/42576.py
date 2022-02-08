def solution(participant, completion):
    dic = dict()
    for i in participant:
        if i in dic:
            dic[i] += 1
        else:
            dic[i] = 1
    for i in completion:
        if dic[i] == 1:
            del dic[i]
        else:
            dic[i] -= 1
    return list(dic.keys())[0]
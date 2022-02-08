def solution(genres, plays):
    answer = []
    hs = dict()
    for i in range(len(genres)):
        if genres[i] in hs:
            hs[genres[i]] += plays[i]
        else:
            hs[genres[i]] = plays[i]

    while len(hs) > 0:
        genre_max = max(hs.keys(), key=(lambda k : hs[k]))
        del(hs[genre_max])

        second = largest = 0
        for i in range(len(genres)):
            if genres[i] == genre_max:
                if plays[i] >= largest:
                    second = largest
                    largest = plays[i]
                elif second < plays[i] < largest:
                    second = plays[i]
        answer.append(plays.index(largest))
        if second != 0:
            answer.append(plays.index(second))
    return answer
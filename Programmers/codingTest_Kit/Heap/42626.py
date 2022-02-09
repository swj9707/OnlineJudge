def solution(scoville, K):
    import heapq
    answer = 0
    PQ = []
    for i in scoville:
        heapq.heappush(PQ, i)
    while PQ[0] < K:
        try:
            heapq.heappush(PQ, heapq.heappop(PQ) + heapq.heappop(PQ)*2)
        except IndexError:
            return -1
        answer +=1
    return answer 
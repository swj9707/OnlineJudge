from collections import defaultdict
def solution(tickets):
    routes = init_graph(tickets)
    for r in routes:
        routes[r].sort()

    N = len(tickets)
    answer = dfs("ICN", ["ICN"], routes, N)

    return answer

def init_graph(tickets):
    routes = defaultdict(list)
    for key, value in tickets:
        routes[key].append(value)
    return routes

def dfs(key, footprint, routes, N):
    if len(footprint) == N + 1:
        return footprint

    for idx, country in enumerate(routes[key]):
        routes[key].pop(idx)

        fp = footprint[:]
        fp.append(country)

        ret = dfs(country, fp, routes, N)
        if ret: return ret

        routes[key].insert(idx, country)
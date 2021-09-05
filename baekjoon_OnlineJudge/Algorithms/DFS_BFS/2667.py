import sys; input = lambda : sys.stdin.readline().rstrip()

n = int(input())

def dfs(x, y):
    if x <= -1 or x >= n or y <= -1 or y >= m:
        return False

import sys ; input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(10**6)

def dfs(data, x, y, W, H):
	if x < 0 or x > W-1 or y < 0 or y > H-1:
		return False
	if data[x][y] == 1:
		data[x][y] = 0
		dfs(data, x + 1 , y, W, H)
		dfs(data, x - 1 , y, W, H)
		dfs(data, x , y - 1, W, H)
		dfs(data, x , y + 1, W, H)
		dfs(data, x + 1 , y - 1, W, H)
		dfs(data, x - 1, y + 1, W, H)
		dfs(data, x + 1 , y + 1, W, H)
		dfs(data, x - 1 , y - 1, W, H)
		return True
	return False

while True:
	W, H = map(int, input().split())
	data = []
	for _ in range(H):
		data.append(list(map(int, input().split())))
	if W == 0 and H == 0:
		break
	count = 0
	for i in range(H):
		for j in range(W):
			if dfs(data, i, j, H, W) == True:
				count += 1
	print(count)

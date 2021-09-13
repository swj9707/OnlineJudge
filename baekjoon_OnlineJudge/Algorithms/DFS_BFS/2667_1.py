import sys ; input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(10**6)

N = int(input())

apt_map = []

for i in range(N):
	apt_map.append(list(map(int, input())))


def dfs(x, y):
	global count
	if x < 0 or x > N-1 or y < 0 or y > N-1:
		return False
	if apt_map[x][y] == 1:
		apt_map[x][y] = 0
		count += 1
		dfs(x - 1 , y)
		dfs(x + 1 , y)
		dfs(x , y + 1)
		dfs(x , y - 1)
		return True
	return False

count = 0
result = 0
num = []

for i in range(N):
	for j in range(N):
		if dfs(i, j) == True:
			num.append(count)
			result += 1
			count = 0

num.sort()
print(result)
for i in range(len(num)):
	print(num[i])

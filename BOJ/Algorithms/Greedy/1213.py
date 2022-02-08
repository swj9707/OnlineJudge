import sys; input = lambda : sys.stdin.readline().rstrip()

name_cnt = [0 for _ in range(26)]

data = input()
for i in data:
    name_cnt[ord(i) - 65] += 1

odd = 0
odd_alpha = ''
alpha = ''

for i in range(26):
    if name_cnt[i] % 2 == 1:
        odd += 1
        odd_alpha += chr(i+65)
    alpha += chr(i+65) * (name_cnt[i] // 2)

if odd > 1:
    print("I'm Sorry Hansoo")
else:
    print(alpha+odd_alpha+alpha[::-1])
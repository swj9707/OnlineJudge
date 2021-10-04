import sys

words = sys.stdin.readline().rstrip()
words = words.upper()
unique_words = list(set(words))

count_list = []

for i in unique_words:
    cnt = word.count(i)
    count_list.append(cnt)

if count_list.count(max(count_list)) > 1:
    print('?')
else:
    maxIndex = count_list.index(max(count_list))
    print(unique_words[maxIndex])

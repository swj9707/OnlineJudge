def returnGrade(avg):
    if avg >= 90:
        return 'A'
    elif avg >= 80 and avg < 90:
        return 'B'
    elif avg >= 70 and avg < 80:
        return 'C'
    elif avg >= 50 and avg < 70:
        return 'D'
    else:
        return 'F'

def solution(scores):
	answer = ''
	
	for i in range(len(scores)):
		data = []
		score = 0
		for j in range(len(scores[0])):
			data.append(scores[j][i])
		if data[i] is max(data):
			if data.count(max(data)) == 1:
				data.remove(max(data))
		elif data[i] is min(data):
			if data.count(min(data)) == 1:
				data.remove(min(data))
		score = sum(data) / len(data)
		answer += returnGrade(score)
	return answer
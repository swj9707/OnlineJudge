Score = int(input())

if Score <= 100 and Score >= 90:
    print('A')
elif Score <= 89 and Score >= 80:
    print('B')
elif Score <= 79 and Score >=70:
    print('C')
elif Score <= 69 and Score >= 60:
    print('D')
else:
    print('F')
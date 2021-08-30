import sys ; input = lambda : sys.stdin.readline().rstrip()
# (1 ¡Â E ¡Â 15, 1 ¡Â S ¡Â 28, 1 ¡Â M ¡Â 19) 
E = 1 ; S = 1; M = 1
e, s, m = map(int, input().split())
year = 1    

while True:
    if E == e and S == s and M == m:
        print(year)
        break
    else:
        E += 1; S += 1; M += 1
        if E > 15 : E = 1
        if S > 28 : S = 1
        if M > 19 : M = 1
        year += 1

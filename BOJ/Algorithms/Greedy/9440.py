def solve(T):
    N = T[0]
    numbers = sorted(T[1:])
    zeros = numbers.count(0)
    n, m = '',''

    for i in range(zeros,len(numbers)):
        if (zeros-i)%2==0: n+= str(numbers[i])
        else: m+= str(numbers[i])
    new_n = n
    new_m = m
    for i in range(zeros):
        if len(n)==len(m):
            if i%2 == 0: new_n = new_n[0]+'0'+new_n[1:]
            else : new_m = new_m[0]+'0'+new_m[1:]
        else: 
            if i%2 == 0: new_m = new_m[0]+'0'+ new_m[1:]
            else : new_n = new_n[0]+'0'+new_n[1:]

    return int(new_n)+int(new_m)
    
if __name__=='__main__':
    T = []
    while True:
        case = list(map(int,input().split()))
        if case==[0]: break
        T.append(case)
    for t in T:
        print(solve(t))
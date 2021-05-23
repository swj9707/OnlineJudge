natural_Num_set = set(range(1,10001))
generalnum = set()

for i in range(1,10001):
    for j in str(i):
        i += int(j)
    generalnum.add(i)

selfnum = sorted(natural_Num_set - generalnum)

for i in selfnum:
    print(i)

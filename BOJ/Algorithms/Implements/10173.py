import sys; input = lambda : sys.stdin.readline().rstrip()

while True:
    N = input()
    if N == 'EOI':
        break
    N = N.lower()
    if 'nemo' in N:
        print("Found")
    else:
        print("Missing")
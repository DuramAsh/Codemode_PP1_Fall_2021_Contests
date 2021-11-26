from math import sqrt
def isPrime(a):
    for i in range(2, int(sqrt(a)) + 1):
        if a % i == 0:
            return False
    return True

start, end = map(int, input().split())

for i in range(start, end + 1):
    if isPrime(i):
        print(i)

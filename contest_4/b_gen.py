from random import *

n = randrange(100, 300)
k = randrange(100, 300)

ll = list()
for i in range(n):
    ll.append(randrange(1, 1000))
f = open('output.txt', 'w')
s = "{} {}\n{}".format(str(n), str(k), ' '.join(map(str, ll)))
f.write(s)
f.close()
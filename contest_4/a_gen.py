from random import *

f = open('output.txt', 'w')
ll = list()
for i in range(30):
    s = ''
    for j in range(randrange(10,15)):
        s += choice([choice([chr(randrange(65,97)), chr(randrange(97,122))]), chr(randrange(48,58))])
    ll.append(s)
t = ','.join(ll)
f.write(t)
f.close()
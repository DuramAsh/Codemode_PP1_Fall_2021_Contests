from random import randrange

with open('output.txt', 'w') as f:
    size = 3
    for i in range(size):
        q = randrange(1e3, 9e3)
        s = f'{q}\n';
        f.write(s)
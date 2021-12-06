from random import randrange

def Convert(string):
    li = list(string.split(","))
    return li


with open('input.txt', 'r') as f:
    ll = f.readlines()

for i in range(len(ll)):
    ll[i] = Convert(ll[i])
# print(*ll, sep='\n')

f = open('output.txt', 'w')
size = 4
for i in ll:
    i[size - 1] = i[size - 1][0:len(i[size - 1]) - 1]
    # print(number)
    s = "INSERT INTO store_product_warehouse VALUES ({}, {}, {}, {});\n".format(*i)
    f.write(s)
f.close()




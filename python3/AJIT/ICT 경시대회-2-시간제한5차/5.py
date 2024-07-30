import math

pq = input().split()
p = int(pq[0])
q = int(pq[1])


def corner(p, q):
    if p % 2 == 1:
        if q % 2 == 1:
            return 3
        else:
            return 4
    else:
        if q % 2 == 1:
            return 2
        else:
            return 1


g = math.gcd(p, q)
p = int(p / g)
q = int(q / g)
history = list()

if p > q:
    for i in range(p, p*q+1, p):
        tmp = list()
        for j in range(i - i % q, i - p, -q):
            if j == p * q:
                continue
            if j / q % 2 == 1:
                tmp.append('N')
            else:
                tmp.append('S')
        tmp.reverse()
        for elem in tmp:
            history.append(elem)

        if i < p * q:
            if i / p % 2 == 1:
                history.append('E')
            else:
                history.append('W')
else:
    for i in range(q, p*q+1, q):
        tmp = list()
        for j in range(i - i % p, i - q, -p):
            if j == p * q:
                continue
            if j / p % 2 == 1:
                tmp.append('E')
            else:
                tmp.append('W')
        tmp.reverse()
        for elem in tmp:
            history.append(elem)

        if i < p * q:
            if i / q % 2 == 1:
                history.append('N')
            else:
                history.append('S')

print(len(history))
history.append(str(corner(p, q)))
print(' '.join(history))

# 21분 00초 52
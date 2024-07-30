n = input()
cars = list(map(int, input().split()))
tmp = list()
nxt = 1

avail = True
while len(cars) > 0 or len(tmp) > 0:
    if len(cars) > 0 and cars[0] == nxt:
        cars.pop(0)
        nxt = nxt + 1
    elif len(tmp) > 0 and tmp[0] == nxt:
        tmp.pop(0)
        nxt = nxt + 1
    elif len(cars) > 0:
        tmp.append(cars[0])
        cars.pop(0)
    else:
        avail = False
        break

if avail:
    print("YES")
else:
    print("NO")

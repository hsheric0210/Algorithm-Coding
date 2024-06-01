i=input().split()
a=ord(i[0])
b=ord(i[1])
c=int(i[2])
r=list(map(chr,range(a,b+1)))
for _ in range(c-1):
    r.append(r[0])
    r.pop(0)
print(''.join(r))

import re
pattern=input()
pattern='(?ai)^'+pattern.replace('?','.').replace('*','.*')+'$'
rx=re.compile(pattern)
n=input()
l=list()
for i in range(int(n)):
    s=input()
    if rx.match(s):
        l.append(s)
print(len(l))
for s in l:
    print(s)

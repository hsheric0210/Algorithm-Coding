# 17504 - 고급-1 - 양팔저울
k = int(input())
g = list(map(int, input().split()))
total = sum(g)
added = []
dp = [0 for i in range(total + 10)]
add_count = 0


def r(off, prev):  # 910 ms
    for i in range(off, k):
        v = prev + g[i]
        added.append(v)
        r(i + 1, v)


# find pos to add 1's
r(0, 0)

# sort & unique
added = list(set(added))
added.sort()  # 아니미틴 pypy3은 set에 넣었다 빼도 정렬이 안돼네..? 이것때문에 하루동안 삽질했다 ;

# add 1's
for i in range(len(added)):
    dp[added[i]] = 1
    add_count = add_count + 1

# greedy add 2's - slow
for i in range(1, len(added)):  # [1, addlen)
    for j in range(i):  # [0, i)
        pos = added[i] - added[j]
        if dp[pos] == 0:
            dp[pos] = 2
            add_count = add_count + 1
print(dp)
print(total - add_count)

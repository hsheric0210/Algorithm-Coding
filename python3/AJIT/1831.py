# 1831 - DFS와 BFS

N, M, V = map(int, input().split())
DV = [False] * (N + 1)
BV = [False] * (N + 1)
D = []
B = []

E = [[] for _ in range(max(N+1,M+1))]
for i in range(M):
    e = list(map(int, input().split()))
    E[e[0]].append(e[1])
    E[e[1]].append(e[0])

for i in range(len(E)):
    E[i].sort()


# dfs
def dfs(node):
    if DV[node]:
        return
    D.append(node)
    DV[node] = True
    for sub in E[node]:
        dfs(sub)


def bfs(node):
    q = [node]
    BV[node] = True
    while not len(q) == 0:
        t = q.pop(0)
        B.append(t)
        for sub in E[t]:
            if not BV[sub]:
                q.append(sub)
                BV[sub] = True


dfs(V)
bfs(V)
print(' '.join(map(str,D)))
print(' '.join(map(str,B)))

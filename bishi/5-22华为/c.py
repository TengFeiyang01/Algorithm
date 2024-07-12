from collections import defaultdict

def solve():
    b, n, m = map(int, input().split())
    dic = defaultdict(list)
    for _ in range(n):
        group, w, v = map(int, input().split())
        dic[group].append((v, w))
    pa = list(map(int, input().split()))
    root = pa.index(-1)
    g = defaultdict(list)
    for u, v in enumerate(pa):
        g[v].append(u)
    f = [[0 for _ in range(b + 1)] for _ in range(m)]
    def dfs(x):
        for y in g[x]:
            dfs(y)
        for j in range(b, -1, -1):
            for y in g[x]:
                for k in range(j, -1, -1):
                    f[x][j] = max(f[x][j], f[x][j - k] + f[y][k])
        q = [0 for _ in range(b + 1)]
        for v, w in dic[x]:
            for j in range(b, v - 1, -1):
                q[j] = max(q[j], q[j - v] + w)
        r = [0 for _ in range(b + 1)]
        for v1 in range(1, b + 1):
            for v2 in range(b - v1 + 1):
                r[v1 + v2] = max(r[v1 + v2], q[v1] + f[x][v2])
        f[x] = r
    dfs(root)
    ans = max(f[root])
    print(ans)

solve()
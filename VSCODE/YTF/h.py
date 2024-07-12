import sys
sys.setrecursionlimit(10000000)

input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


# 左闭右闭
class FenWick:
    def __init__(self, n: int):
        self.n = n
        self.tr = [0 for _ in range(n + 1)]

    def sum(self, i: int):
        i += 1
        s = 0
        while i >= 1:
            s += self.tr[i]
            i &= i - 1
        return s

    def rangeSum(self, l: int, r: int):
        return self.sum(r) - self.sum(l - 1)

    def add(self, i: int, val: int):
        i += 1
        while i <= self.n:
            self.tr[i] += val
            i += i & -i


def solve():
    n, s = mint()
    a = ints()
    a = [0] + a
    adj = [[] for _ in range(n + 1)]
    for i in range(n - 1):
        x, y = mint()
        adj[x].append(y)

    id = [0] * (n + 1)
    for i in range(1, n + 1):
        id[a[i]] = i

    cnt = 0
    l = [0] * (n + 1)
    r = [0] * (n + 1)
    size = [0] * (n + 1)
    son = [0] * (n + 1)

    def eula(u):
        nonlocal cnt
        cnt += 1
        l[u] = cnt
        size[u] = 1
        for v in adj[u]:
            size[u] += eula(v)
            if size[v] > size[son[u]]:
                son[u] = v
        r[u] = cnt
        return size[u]
    eula(s)

    cnt = [0] * (n + 1)
    tr = FenWick(n + 10)

    def Add(u, x):
        nonlocal tr
        tr.add(a[u], x)
        for v in adj[u]:
            Add(v, x)
        

    def dfs(u, keep):
        nonlocal cnt
        for v in adj[u]:
            if v != son[u]:
                dfs(v, False)
        if son[u]: dfs(son[u], True)

        for v in adj[u]:
            if v != son[u]:
                Add(v, 1)
        
        tr.add(a[u], 1)
        cnt[u] = tr.sum(a[u] - 1) 
        if not keep:
            tr.add(a[u], -1)
            for v in adj[u]:
                Add(v, -1)

    dfs(s, True)
    
    factors = [[] for _ in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(i * 2, n + 1, i):
            factors[j].append(i)
    
    b = []
    for i in range(1, n + 1):
        b.append([a[i], i])
    b.sort()

    ans = sum(cnt)
    # cnt 表示满足条件的答案个数
    for x, i in b:
        p = 0
        for y in factors[x]:
            if l[id[y]] >= l[i] and r[id[y]] <= r[i]:
                ans -= 1
    print(ans)



if __name__ == '__main__':
    solve()
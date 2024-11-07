from collections import defaultdict
from math import isqrt
from sys import stdin, stdout

def get(x):
    count = 0
    for i in range(2, isqrt(x) + 1):
        if x % i == 0:
            count += 1
            while x % i == 0:
                x //= i
    if x > 1:
        count += 1
    return count

def solve():
    # 输入
    n = int(stdin.readline().strip())
    a = list(map(int, stdin.readline().strip().split()))

    # 计算每个节点的质因子个数
    cnt = [0] * n
    for i in range(n):
        cnt[i] = get(a[i])

    # 构建树的邻接表
    adj = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v = map(int, stdin.readline().strip().split())
        adj[u - 1].append(v - 1)
        adj[v - 1].append(u - 1)
    # 从根节点开始DFS
    ans = []
    
    def dfs(u, fa):
        nonlocal ans
        ok = False
        son = False
        for v in adj[u]:
            if v == fa: continue
            x = dfs(v, u)
            son = son or x
        if fa != -1 and cnt[fa] == cnt[u]:
            ok = True
        if not son and ok:
            ans.append(u+1)
        return ok or son
    dfs(0, -1)
    print(len(ans))
    print(*ans)        
solve()
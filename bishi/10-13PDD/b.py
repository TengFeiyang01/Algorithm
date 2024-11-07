import sys
from collections import defaultdict

sys.setrecursionlimit(10**6)


adj = defaultdict(list)
dp = [0] * (200003)
st = [0] * (200003)
a = [0]

def dfs(u, fa):
    global dp[1], a
    cur = a[u]  
    mx1, mx2 = 0, 0  

    for v, w in adj[u]:
        if v == fa:
            continue

        son = dfs(v, u) - w 

        if son > 0:
            cur = max(cur, a[u] + son)

            if son > mx1:
                mx2 = mx1
                mx1 = son
            elif son > mx2:
                mx2 = son

    dp[1] = max(dp[1], cur)
    dp[1] = max(dp[1], a[u] + mx1 + mx2)  
    return a[u] + mx1

def reroot(u, fa):
    
    

def solve():
    global dp[1]
    n = int(input())
    global a
    a += list(map(int, input().split()))

    for i in range(n-1):
        u, v, w = map(int, input().split())
        adj[u].append((v, w))
        adj[v].append((u, w))

    dfs(1, 0)


if __name__ == "__main__":
    solve()

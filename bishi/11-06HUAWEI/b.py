import sys
from collections import *

input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))

def solve() -> None:
    n = sint()
    adj = [[] for _ in range(n)] 
    for i in range(n):
        t = list(input().split())
        u = int(t[0].split(':')[0])
        for p in t[1:]:
            v = int(p)
            adj[u].append(v)  
            adj[v].append(u)
    
    dp = [[-1, -1] for _ in range(n)]
    
    def dfs(u, parent):
        dp[u][0] = 0 
        dp[u][1] = 1 
        
        for v in adj[u]:
            if v == parent:
                continue
            dfs(v, u)
            
            dp[u][0] += dp[v][1]
            dp[u][1] += min(dp[v][0], dp[v][1])
    
    dfs(0, -1)
    
    print(min(dp[0][0], dp[0][1]))


if __name__ == '__main__':
    solve()

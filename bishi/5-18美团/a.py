import sys


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))

sys.setrecursionlimit(500000)

def solve() -> None:
    n = sint()
    s = input()
    adj = [[] for _ in range(n)]
    for i in range(n - 1):
        x, y = mint()
        adj[x - 1].append(y - 1)
        adj[y - 1].append(x - 1)
    
    size = [1] * n
    dp = [0] * n
    
    def dfs(u, fa, cnt):
        if s[u] == 'R':
            cnt += 1
        if u != 0:
            dp[0] += cnt
        for v in adj[u]:
            if v != fa:
                dfs(v, u, cnt)
                size[u] += size[v]
    
    dfs(0, -1, 0)
        
    def reroot(u, fa):
        for v in adj[u]:
            if v != fa:
                dp[v] = dp[u]
                if s[u] == 'R' and s[v] == 'W':
                    dp[v] += 1 - size[v]
                if s[u] == 'W' and s[v] == 'R':
                    dp[v] += n - size[v] - 1
                if s[u] == 'R' and s[v] == 'R':
                    dp[v] += n - 2 * size[v]
                reroot(v, u)  
                
    reroot(0, -1)
    print(*dp)
    
if __name__ == '__main__':
    solve()
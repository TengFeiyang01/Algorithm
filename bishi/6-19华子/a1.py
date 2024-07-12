import sys

sys.setrecursionlimit(100000)

input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))
from collections import *

def solve() -> None:
    n = sint()
    adj = [[] for _ in range(n)]
    d = [0] * n
    dp = [0] * n
    for i in range(n):
        t = ints()
        for j in range(1, t[0] + 1):
            adj[t[j] - 1].append(i)
            d[i] += 1
    
    q = deque()
    for i in range(n):
        if d[i] == 0:
            q.append(i)
    cnt = 0
    while q:
        cnt += 1
        u = q.popleft()
        for v in adj[u]:
            d[v] -= 1
            dp[v] = max(dp[v], dp[u] + 1)
            if d[v] == 0:
                q.append(v)        
    
    if cnt != n:
        print(-1)
    else:
        print(max(dp)+1)
    


if __name__ == '__main__':
    solve()
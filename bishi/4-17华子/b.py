
import sys

from collections import defaultdict, deque

def solve() -> None:
    m, n = map(int, input().split())
    adj = defaultdict(list)
    root = set()
    p = [defaultdict(int), defaultdict(int)]
    d = defaultdict(int)
    node = set()

    for i in range(n):
        u, v, level, cnt = input().split()
        level, cnt = int(level), int(cnt)

        if v == "*":
            root.add(u)
        else:
            adj[u].append(v)
            d[v] += 1
        p[level][u] = cnt
        node.add(u)

    ans = 0
    q = deque()
    for u in node:
            if d[u] == 0:
                q.append(u)
    
    while q:
        u = q.popleft()
        for v in adj[u]:
            p[0][v] += p[0][u]
            p[1][v] += p[1][u]
            d[v] -= 1
            if d[v] == 0:
                q.append(v)
    
    for u in root:
        if p[0][u] * 5 + p[1][u] * 2 > m:
            ans += 1
    print(ans)

if __name__ == '__main__':
    solve()
from collections import defaultdict, deque
import sys

input = sys.stdin.readline

def bfs(st, adj, dp):
    queue = deque(st)
    for idx in st:
        dp[idx] = 0

    while queue:
        u = queue.popleft()
        for p in routes[u]:
            for v in adj[p]:
                if dp[v] > dp[u] + 1:
                    dp[v] = dp[u] + 1
                    queue.append(v)

def main():
    a, b, c = map(int, input().split())
    n = int(input())
    
    inf = float('inf')
    global routes
    routes = []

    adj = defaultdict(list)
    dp = [inf] * n

    for i in range(n):
        route = list(map(int, input().split()))
        k = route[0]
        stops = route[1:k + 1]
        routes.append(stops)
        for stop in stops:
            adj[stop].append(i)

    bfs(adj[b], adj, dp)

    x = min(dp[idx] for idx in adj[a]) if adj[a] else inf
    y = min(dp[idx] for idx in adj[c]) if adj[c] else inf

    if x == inf or y == inf:
        print(-1)
    else:
        print(x + y + 1)

if __name__ == "__main__":
    main()

import heapq

def main():
    n = int(input())
    m = int(input())
    str_chars = list(input().strip())
    
    # Graph adjacency list
    g = [[] for _ in range(n)]
    
    for _ in range(m):
        u, v, w, c = map(int, input().split())
        u -= 1
        v -= 1
        g[u].append((v, w, c))
        g[v].append((u, w, c))
    
    inf = float('inf')
    dp = [[[inf, inf] for _ in range(n)] for _ in range(2)]
    dp[0][0] = [0, 0]
    
    # Min heap (priority queue)
    pp = []
    heapq.heappush(pp, (0, 0, 0, 0))  # (d, u, w, c)
    
    while pp:
        d, u, w, c = heapq.heappop(pp)
        
        if w > dp[d][u][0] or (w == dp[d][u][0] and c > dp[d][u][1]):
            continue
        
        for v, w1, c1 in g[u]:
            if str_chars[u] != str_chars[v]:
                if d == 0:
                    if dp[1][v][0] > w + w1 or (dp[1][v][0] == w + w1 and dp[1][v][1] > c + c1):
                        dp[1][v][0] = w + w1
                        dp[1][v][1] = c + c1
                        heapq.heappush(pp, (1, v, w + w1, c + c1))
            else:
                if dp[d][v][0] > w + w1 or (dp[d][v][0] == w + w1 and dp[d][v][1] > c + c1):
                    dp[d][v][0] = w + w1
                    dp[d][v][1] = c + c1
                    heapq.heappush(pp, (d, v, w + w1, c + c1))
    
    if dp[1][n - 1][0] == inf:
        print(-1)
    else:
        print(dp[1][n - 1][0], dp[1][n - 1][1])

if __name__ == "__main__":
    main()
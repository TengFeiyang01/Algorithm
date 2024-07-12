import sys
import heapq

inf = float('inf')
dirs = [-1, 0, 1, 0, -1]

def solve():
    input = sys.stdin.readline
    n, m = map(int, input().split())
    
    
    s = [[] for _ in range(n)]
    f = [[inf] * m for _ in range(n)]
    g = [[inf] * m for _ in range(n)]
    digit = [[0] * m for _ in range(n)]
    
    pq1 = []
    pq2 = []
    
    for i in range(n):
        s[i] = list(input().split())
        for j in range(m):
            if s[i][j] == "S":
                f[i][j] = 0
                heapq.heappush(pq1, (0, i * m + j))
            elif s[i][j] == "E":
                g[i][j] = 0
                heapq.heappush(pq2, (0, i * m + j))
            elif s[i][j] not in ("C", "B"):
                digit[i][j] = int(s[i][j])
    
    def check(i, j):
        return digit[i][j] != 0 or s[i][j] != "B"
    
    def update(dp, pq):
        while pq:
            d, t = heapq.heappop(pq)
            x, y = divmod(t, m)
            for k in range(4):
                nx, ny = x + dirs[k], y + dirs[k + 1]
                if 0 <= nx < n and 0 <= ny < m and check(nx, ny):
                    if digit[nx][ny]:
                        w = digit[nx][ny]
                        if dp[nx][ny] > dp[x][y] + w:
                            dp[nx][ny] = dp[x][y] + w
                            heapq.heappush(pq, (dp[nx][ny], nx * m + ny))
                    else:
                        if dp[nx][ny] > dp[x][y]:
                            dp[nx][ny] = dp[x][y]
                            heapq.heappush(pq, (dp[nx][ny], nx * m + ny))
    
    update(f, pq1)
    update(g, pq2)
    
    ans = inf
    for i in range(n):
        for j in range(m):
            if s[i][j] == "C" and f[i][j] != inf and g[i][j] != inf:
                ans = min(ans, f[i][j] + g[i][j])
    
    if ans == inf:
        ans = -1
    print(ans)

if __name__ == "__main__":
    solve()

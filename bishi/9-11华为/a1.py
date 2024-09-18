INF = float('inf')

def solve():
    n, m = map(int, input().split())
    g = []
    dist = [[INF] * m for _ in range(n)]
    queue = []

    for i in range(n):
        row = list(map(int, input().split()))
        g.append(row)
        for j in range(m):
            if row[j] == 0:
                queue.append((i, j))
                dist[i][j] = 0

    dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    while queue:
        i, j = queue.pop(0)
        for di, dj in dirs:
            x, y = i + di, j + dj
            if 0 <= x < n and 0 <= y < m and g[x][y] != -1:
                if dist[i][j] + 1 < dist[x][y]:
                    dist[x][y] = dist[i][j] + 1
                    queue.append((x, y))

    ans = 0
    for i in range(n):
        for j in range(m):
            if g[i][j] == 1 and dist[i][j] != INF:
                ans += dist[i][j]

    print(ans)

if __name__ == "__main__":
    solve()

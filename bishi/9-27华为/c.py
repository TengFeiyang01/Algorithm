from collections import deque

def main():
    h, w, a, b, c, d = map(int, input().split())
    
    inf = float('inf')
    g = []
    dp = [[0] * w for _ in range(h)]
    days = [[inf] * w for _ in range(h)]

    pq = deque()
    
    for i in range(h):
        row = list(map(int, input().split()))
        g.append(row)
        for j in range(w):
            if g[i][j] == 2:
                dp[i][j] = b
                pq.append((i, j, b, 0))
            elif g[i][j] == 3:
                dp[i][j] = a
                pq.append((i, j, a, 0))

    dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    while pq:
        y, x, val, day = pq.popleft()
        if val < dp[y][x]:
            continue

        for dy, dx in dirs:
            ty, tx = y + dy, x + dx
            if 0 <= ty < h and 0 <= tx < w:
                if g[ty][tx] == 1:
                    continue
                if dp[ty][tx] < val - 1:
                    dp[ty][tx] = val - 1
                    if g[ty][tx] == 4 and dp[ty][tx] >= d:
                        dp[ty][tx] = b
                        days[ty][tx] = min(days[ty][tx], day + 1)
                        pq.append((ty, tx, b, day + 1))
                    elif g[ty][tx] == 5 and dp[ty][tx] >= c:
                        dp[ty][tx] = a
                        days[ty][tx] = min(days[ty][tx], day + 1)
                        pq.append((ty, tx, a, day + 1))
                    else:
                        pq.append((ty, tx, dp[ty][tx], day))

    res = [[0] * w for _ in range(h)]
    for i in range(h):
        for j in range(w):
            if g[i][j] == 2 or g[i][j] == 3:
                res[i][j] = 0
            elif g[i][j] <= 1:
                res[i][j] = -1
            else:
                if days[i][j] == inf:
                    res[i][j] = -1
                else:
                    res[i][j] = days[i][j]

    for row in res:
        print(" ".join(map(str, row)))

if __name__ == "__main__":
    main()

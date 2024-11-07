import sys
from collections import deque

def solve():
    m = int(input())
    n = int(input())

    sx, sy = map(int, input().split())
    tx, ty = map(int, input().split())

    k = int(input())
    inf = 0x3f3f3f3f
    dist = [[inf for _ in range(n)] for _ in range(m)]

    sx -= 1
    sy -= 1
    tx -= 1
    ty -= 1

    dist[sx][sy] = 0

    for _ in range(k):
        x, y = map(int, input().split())
        x -= 1
        y -= 1
        dist[x][y] = -1

    dir = [(-1, 0), (0, 1), (1, 0), (0, -1)]

    queue = deque()
    queue.append((sx, sy))

    while queue:
        x, y = queue.popleft()

        for dx, dy in dir:
            i, j = x + dx, y + dy

            if 0 <= i < m and 0 <= j < n:
                if dist[i][j] == -1:
                    continue  # Blocked cell
                if dist[i][j] > dist[x][y] + 1:
                    dist[i][j] = dist[x][y] + 1
                    queue.append((i, j))

    result = dist[tx][ty]
    if result == inf:
        result = -1
    print(result)

if __name__ == "__main__":
    solve()
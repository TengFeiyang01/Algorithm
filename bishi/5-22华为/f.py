from collections import deque

def solve(H, n, m, s):
    dir = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    
    sx = sy = ex = ey = -1
    heights = []
    
    for i in range(n):
        row = []
        for j in range(m):
            if s[i][j] == 's':
                sx, sy = i, j
                row.append(float('inf')) 
            elif s[i][j] == 't':
                ex, ey = i, j
                row.append(float('inf')) 
            elif s[i][j] == '0':
                row.append(0) 
            else:
                row.append(int(s[i][j])) 
        heights.append(row)
    
    queue = deque([(sx, sy, 0)])
    visited = [[False] * m for _ in range(n)]
    visited[sx][sy] = True
    prev = [[None] * m for _ in range(n)]
    
    while queue:
        x, y, time = queue.popleft()
        
        if (x, y) == (ex, ey):
            path = []
            now = (x, y)
            while now is not None:
                path.append(s[now[0]][now[1]])
                now = prev[now[0]][now[1]]
            path.reverse()
            return " ".join(path)
        
        for dx, dy in dir:
            nx, ny = x + dx, y + dy
            
            if 0 <= nx < n and 0 <= ny < m and not visited[nx][ny]:
                if heights[nx][ny] > H + time + 1:
                    visited[nx][ny] = True
                    prev[nx][ny] = (x, y)
                    queue.append((nx, ny, time + 1))
    return 's'

H = int(input().strip())
n, m = map(int, input().split())
s = []
for _ in range(n):
    s.append(input().rstrip().split())

print(solve(H, n, m, s))

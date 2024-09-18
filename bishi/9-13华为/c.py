from collections import deque

dirs = [-1, 0, 1, 0, -1]
inf = float('inf')

def solve():
    p = int(input())
    n, m = map(int, input().split())
    
    g = [[0] * m for _ in range(n)]
    pre = [[0] * m for _ in range(n)]
    
    sx = sy = tx = ty = 0
    
    for i in range(n):
        line = input().split()
        for j in range(m):
            if line[j] == 's':
                sx, sy = i, j
                g[i][j] = p
            elif line[j] == 't':
                tx, ty = i, j
                g[i][j] = inf
            else:
                g[i][j] = int(line[j])
    
    q = deque([(sx * m + sy, p)])
    st = set()
    st.add(sx * m + sy)
    ok = False
    
    while q:
        t = q.popleft()
        i, j, h = t[0] // m, t[0] % m, t[1]
        if i == tx and j == ty:
            ok = True
        
        for k in range(4):
            x, y = i + dirs[k], j + dirs[k + 1]
            nh = h + 1
            if 0 <= x < n and 0 <= y < m and g[x][y] > nh and (x * m + y) not in st:
                pre[x][y] = i * m + j
                st.add(x * m + y)
                q.append((x * m + y, nh))
    
    ans = []
    if ok:
        ans.append('t')
        x, y = tx, ty
        while x * m + y != sx * m + sy:
            cx, cy = pre[x][y] // m, pre[x][y] % m
            if cx == sx and cy == sy:
                ans.append('s')
            else:
                ans.append(str(g[cx][cy]))
            x, y = cx, cy
        ans.reverse()
        print(' '.join(ans))
    else:
        print('s')

if __name__ == "__main__":
    solve()

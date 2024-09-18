def check(g, x, y):
    if x + 1 >= len(g) or y + 1 >= len(g):
        return False
    return not g[x][y] and not g[x+1][y] and not g[x][y+1] and not g[x+1][y+1]

def add(g, x, y):
    g[x][y] = g[x+1][y] = g[x][y+1] = g[x+1][y+1] = True

def delete(g, x, y):
    g[x][y] = g[x+1][y] = g[x][y+1] = g[x+1][y+1] = False

def backtrack(g, x, y, cnt):
    if y == len(g):
        y = 0
        x += 1
    if x == len(g):
        return cnt
    
    ans = cnt
    if check(g, x, y):
        add(g, x, y)
        ans = max(ans, backtrack(g, x, y + 2, cnt + 1))
        delete(g, x, y)
    
    ans = max(ans, backtrack(g, x, y + 1, cnt))
    
    return ans

import sys
sys.setrecursionlimit(1000000)

def solve():
    n, k = map(int, input().split())
    g = [[False] * n for _ in range(n)]
    for i in range(k):
        x, y = map(int, input().split())
        g[x][y] = True        
    
    print(backtrack(g, 0, 0, 0))

if __name__ == '__main__':
    solve()
import sys
import math
from collections import deque

def solve():
    n, k = map(int, input().split())
    
    p = []
    
    x0, y0 = map(int, input().split())
    
    p.append((x0, y0, 0))
    for _ in range(n):
        x, y, h = map(float, input().split())
        p.append((x, y, h))
    
    p.append((x0, y0, float('inf')))
    
    p.sort(key=lambda x: x[2] if x[2] is not None else float('inf'))
    
    def getDis(i, j):
        dx = p[i][0] - p[j][0]
        dy = p[i][1] - p[j][1]
        return math.sqrt(dx * dx + dy * dy)
    
    ans = 0
    for i in range(n):
        ans += getDis(i, i + 1)
    ans += getDis(n, 0)
    
    dp = [0] * (n + 1)
    q = deque([0])
    
    for i in range(1, n + 1):
        while q and i - q[0] > k:
            q.popleft()
        
        dp[i] = dp[q[0]] + getDis(0, i) + getDis(0, i + 1) - (getDis(i, i + 1) if i < n else 0)
        
        while q and dp[q[-1]] >= dp[i]:
            q.pop()
        
        q.append(i)
    
    mv = float('inf')
    for i in range(n - k, n + 1):
        mv = min(mv, dp[i])
    
    print(f"{ans + mv:.1f}")

if __name__ == "__main__":
    input = sys.stdin.readline
    solve()

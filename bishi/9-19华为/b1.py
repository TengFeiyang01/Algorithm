import sys
from collections import deque

input = sys.stdin.readline
dirs = [-1, 0, 1, 0, -1]
INF = 10**6

def solve():
    n = int(sys.stdin.readline())
    k = int(sys.stdin.readline())
    g = []
    for _ in range(n):
        g.extend(map(int, sys.stdin.readline().split()))

    # 内嵌的 check 函数，使用下标映射和访问数组
    def check(mx):
        q = deque([0])  # 初始位置 (0, 0) 映射为 0
        visited = [False] * (n * n)
        visited[0] = True

        dist = 0
        while q:
            for _ in range(len(q)):
                idx = q.popleft()
                x = idx // n
                y = idx % n

                if x == n - 1 and y == n - 1:
                    return dist <= k  # 到达目标点

                for d in range(4):
                    nx, ny = x + dirs[d], y + dirs[d + 1]
                    if 0 <= nx < n and 0 <= ny < n:
                        new_idx = nx * n + ny
                        if not visited[new_idx] and g[new_idx] <= mx:
                            visited[new_idx] = True
                            q.append(new_idx)
            dist += 1
        return False

    # 二分查找最小的 mx
    l, r = 0, INF
    while l < r:
        mid = (l + r) // 2
        if check(mid):
            r = mid
        else:
            l = mid + 1
    print(l)

if __name__ == '__main__':
    solve()

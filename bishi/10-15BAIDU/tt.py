import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache
from math import *
from collections import *


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))

def dfs(x, y, d, visited, a, n):
    # 检查边界条件
    if x < 0 or x >= n or y < 0 or y >= n:
        return inf
    # 如果已经访问过，返回inf避免重复访问
    if visited[x][y]:
        return inf
    
    # 目标点
    if x == n-1 and y == n-1:
        return d
    
    # 标记当前点为已访问
    visited[x][y] = True
    
    # 初始化最小距离为inf
    min_dist = inf
    
    # 尝试所有可能的移动
    if y + 1 < n and a[x][y + 1] != 0:
        min_dist = min(min_dist, dfs(x, y + 1, d + 1, visited, a, n))
    if y - 1 >= 0 and a[x][y - 1] != 0:
        min_dist = min(min_dist, dfs(x, y - 1, d + 1, visited, a, n))
    if x + 1 < n and a[x + 1][y] != 0:
        min_dist = min(min_dist, dfs(x + 1, y, d + 1, visited, a, n))
    if x - 1 >= 0 and a[x - 1][y] != 0:
        min_dist = min(min_dist, dfs(x - 1, y, d + 1, visited, a, n))
    
    # 返回当前点为未访问状态（回溯）
    visited[x][y] = False
    
    return min_dist

def solve(test) -> None:
    n = sint()
    a = [ints() for _ in range(n)]
    visited = [[False] * n for _ in range(n)]
    result = dfs(0, 0, 0, visited, a, n)
    print(f"test {test}: {result if result != inf else -1}")

if __name__ == '__main__':
    T = sint()
    for i in range(T):
        solve(i + 1)
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

def escape_castle(rows, cols, walls, escape_point):
    grid = [[0] * cols for _ in range(rows)]

    # 设置墙壁
    for x, y in walls:
        grid[x][y] = -1

    # BFS 初始化
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    queue = deque([(0, 0, 0)])
    visited = [[False] * cols for _ in range(rows)]
    visited[0][0] = True

    # BFS 遍历
    while queue:
        x, y, steps = queue.popleft()

        # 如果到达了逃生点
        if [x, y] == escape_point:
            return steps

        # 遍历四个方向
        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if 0 <= nx < rows and 0 <= ny < cols and grid[nx][ny] != -1 and not visited[nx][ny]:
                visited[nx][ny] = True
                queue.append((nx, ny, steps + 1))

    # 如果无法到达逃生点
    return -1

from collections import deque


def escape_castle1(rows, cols, walls, escape_point, treasures):
    grid = [[0] * cols for _ in range(rows)]
    treasure_set = {(x, y) for x, y in treasures}
    max_treasures = len(treasures)  # 最大宝藏数

    # 设置墙壁
    for x, y in walls:
        grid[x][y] = -1

    # BFS 初始化
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    queue = deque([(0, 0, 0, 0)])  # (行, 列, 步数, 收集的宝藏数)
    visited = [[[False] * (max_treasures + 1) for _ in range(cols)] for _ in range(rows)]
    visited[0][0][0] = True

    min_steps = float('inf')
    collected_treasures = 0

    # BFS 遍历
    while queue:
        x, y, steps, collected = queue.popleft()

        if [x, y] == [rows-1, cols-1]:
            if collected > collected_treasures or (collected == collected_treasures and steps < min_steps):
                collected_treasures = collected
                min_steps = steps
            continue

        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if 0 <= nx < rows and 0 <= ny < cols and grid[nx][ny] != -1:
                new_collected = collected
                if (nx, ny) in treasure_set:
                    new_collected += 1

                if new_collected <= max_treasures and not visited[nx][ny][new_collected]:
                    visited[nx][ny][new_collected] = True
                    queue.append((nx, ny, steps + 1, new_collected))

    # 如果无法到达逃生点
    if min_steps == float('inf'):
        return [-1, 0]

    return [min_steps, collected_treasures]

def solve() -> None:
    print(escape_castle(2, 2, [[0, 1]], [1, 1]))
    print(escape_castle1(3, 3, [[1, 1]], [1, 1], [[0, 1]]))


if __name__ == '__main__':
    solve()
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




def solve() -> None:
    n, m = map(int, input().split(','))
    x, y = map(int, input().split(','))
    t = list(input().split())
    for i in range(len(t)):
        t[i] = list(map(int, t[i].split(',')))
    obstacle = list(input().split())
    for i in range(len(obstacle)):
        obstacle[i] = list(map(int, obstacle[i].split(',')))

    direc = [0, 1, 0, -1, 0]
    res = [[False] * 100 for _ in range(100)]
    passed = [[[False] * 105 for _ in range(100)] for _ in range(100)]
        
    def dfs(x, y, speed):

        if speed == 1:
            res[x][y] = True
        if speed < 1:
            return
        if passed[x][y][speed]:
            return
        passed[x][y][speed] = True
        for i in range(4):
            xt = x + direc[i]
            yt = y + direc[i + 1]
            if 0 <= xt < n and 0 <= yt < m:
                dfs(xt, yt, speed + t[x][y] - t[xt][yt] - obstacle[xt][yt])
    
    n = len(t)
    m = len(t[0])
    dfs(x, y, 1)
    ans = 0
    res[x][y] = False
    for i in range(100):
        for j in range(100):
            if res[i][j]:
                ans += 1
    print(ans)


if __name__ == '__main__':
    solve()
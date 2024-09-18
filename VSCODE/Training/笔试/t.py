import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush, heapreplace, heappushpop
from functools import lru_cache
from math import inf
from collections import *


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))
sys.setrecursionlimit(1000000)


def solve() -> None:
    n, k = mint()
    a = [ints() for i in range(n)]
    
    step_queues = [[] for _ in range(k)]
    
    ans = 0

    for _ in range(n):
        cur = 0  # 每个蛋糕开始的时间
        for step in range(k):
            t = a[step][1]
            if len(step_queues[step]) < a[step][0]:
                heapq.heappush(step_queues[step], cur + t)
            else:
                cur = heapq.heappushpop(step_queues[step], cur + t)
            cur += t
            ans = max(ans, cur)
    print(ans)


if __name__ == '__main__':
    solve()
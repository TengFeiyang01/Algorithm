import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache
from math import *


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


from collections import defaultdict, deque

def solve() -> None:
    n = int(input().strip())
    adj = defaultdict(list)
    in_degree = defaultdict(int)
    node = set()

    for _ in range(n):
        p = input().strip().split()
        u = p[0]
        node.add(u)
        for v in p[1:]:
            adj[v].append(u)
            in_degree[u] += 1
            node.add(v)

    # 拓扑排序
    q = deque()
    for k in node:
        if in_degree[k] == 0:
            q.append(k)

    count = 0
    while q:
        u = q.popleft()
        count += 1
        for v in adj[u]:
            in_degree[v] -= 1
            if in_degree[v] == 0:
                q.append(v)

    if count == len(node):
        print(-1)
    else:
        print(len(node) - count)

if __name__ == '__main__':
    solve()
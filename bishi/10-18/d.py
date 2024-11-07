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
class DSU:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n
        self.n = n
        self.setCount = n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        x, y = self.find(x), self.find(y)
        if x == y:
            return False
        if self.size[x] < self.size[y]:
            x, y = y, x
        self.parent[y] = x
        self.size[x] += self.size[y]
        self.setCount -= 1
        return True

    def connected(self, x, y):
        x, y = self.find(x), self.find(y)
        return x == y


def solve() -> None:
    s = input()
    odd = 0
    p = ""
    # 等价于最小回文串
    # 奇数个数大于1无解
    # 构造前半部分即可 
    cnt = defaultdict(int)
    for x in s:
        cnt[x] += 1
    a = []
    for k, v in cnt.items():
        if v % 2:
            p = k
            odd += 1
        a.append((k, v // 2))
    if odd > 1:
        print("-1")
    else:
        a.sort()
        res = ""
        for k, v in a:
            res = res + k * v
        print(res + p + res[::-1])

if __name__ == '__main__':
    solve()
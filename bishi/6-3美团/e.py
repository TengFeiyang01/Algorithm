import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache
from math import inf


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


# 左闭右闭
class FenWick:
    def __init__(self, n: int):
        self.n = n
        self.tr = [0 for _ in range(n + 1)]

    def sum(self, i: int):
        i += 1
        s = 0
        while i >= 1:
            s += self.tr[i]
            i &= i - 1
        return s

    def rangeSum(self, l: int, r: int):
        return self.sum(r) - self.sum(l - 1)

    def add(self, i: int, val: int):
        i += 1
        while i <= self.n:
            self.tr[i] += val
            i += i & -i

def solve() -> None:
    n = sint()
    tr = FenWick(n)
    a = ints()
    ans = inf
    pre = [0] * (n + 2)
    suf = [0] * (n + 2)
    
    for i in range(1, n + 1):
        pre[i] = pre[i - 1] + tr.sum(a[i - 1] - 1)
        tr.add(a[i - 1] - 1, 1)
    tr = FenWick(n)
    for i in range(n, 0, -1):
        suf[i] = suf[i + 1] + tr.sum(a[i - 1] - 1)
        tr.add(a[i - 1] - 1, 1)
    for i in range(0, n + 1):
        ans = min(ans, pre[i] + suf[i + 1])
    print(ans)
    
    


if __name__ == '__main__':
    solve()
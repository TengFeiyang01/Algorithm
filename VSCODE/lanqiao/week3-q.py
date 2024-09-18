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


def solve() -> None:
    k, n = mint()
    a = ints()
    st = [0] * k
    res = [1]

    for i in range(n):
        ans = inf
        for i, x in enumerate(a):
            p = res[st[i]] * x
            if p < ans: ans = p
        for i, x in enumerate(x):
            p = res[st[i]] * x
            if p == ans:
                st[i] += 1
        res.append(ans)
    print(res[-1])
        


if __name__ == '__main__':
    solve()
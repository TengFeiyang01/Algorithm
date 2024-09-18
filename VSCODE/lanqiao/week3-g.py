import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache
from math import inf
from bisect import bisect_left, bisect_right
from collections import defaultdict


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


def solve() -> None:
    n, k = mint()
    a = ints()
    cnt = defaultdict(int)
    for x in a:
        cnt[x] += 1
    ans, x = 0, n
    while ans < n:
        x -= cnt[ans]
        if x + min(cnt[ans], k) <= ans:
            break
        ans += 1
    print(ans)

if __name__ == '__main__':
    solve()

import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from bisect import bisect_left, bisect_right
from functools import lru_cache
from math import inf


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


def solve() -> None:
    n, x = mint()
    a = ints()
    a.sort()
    ans = 0
    i, j = bisect_left(a, x), bisect_right(a, x)-1
    if i == n or a[i] != x:
        ans = 1
        j = i
        n += 1
    m = (n - 1) // 2
    if i > m:
        ans += i * 2 - n + 1
    elif j < m:
        ans += n - j * 2 - 2
    print(ans)


if __name__ == '__main__':
    solve()
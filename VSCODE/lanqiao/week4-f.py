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
    n = sint()
    a = [ints() for _ in range(n)]

    a.sort()

    last = a[0][1]
    b = [a[0]]
    ans = res = 0
    ans = a[0][1] - a[0][0]
    for l, r in a[1:]:
        if l > b[-1][1]:
            res = max(res, l - b[-1][1])
            b.append([l, r])
        else:
            b[-1][1] = max(b[-1][1], r)
        ans = max(ans, b[-1][1] - b[-1][0])
    print(ans, res)


if __name__ == '__main__':
    solve()
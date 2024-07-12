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
    ans = 0
    while n:
        t = 0
        cur = n
        while cur:
            t += cur % 10
            cur //= 10
        n -= t
        ans += 1
    print(ans)


if __name__ == '__main__':
    solve()
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
    s, ans = input(), 0
    for i in range(len(s)):
        lp = s.rfind(s[i], 0, i)
        rp = s.find(s[i], i + 1) % (len(s) + 1)
        ans += (i - lp) * (rp - i)
    print(ans)

if __name__ == '__main__':
    solve()
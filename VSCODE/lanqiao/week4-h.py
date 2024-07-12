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
    a, b = mint()
    cnt = [0] * (a + 2)
    for i in range(b):
        l, r = mint()
        cnt[l] += 1
        cnt[r + 1] -= 1
        
    ans = a + 1
    for i in range(a + 1):
        if i: cnt[i] += cnt[i - 1]
        if cnt[i] > 0: ans -= 1
        
    print(ans)

if __name__ == '__main__':
    solve()
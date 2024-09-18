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
    n, d, k = mint()
    ans = set()
    a = [ints() for i in range(n)]
    a.sort()
    cnt = [0] * (100001)
    j = 0
    for i in range(n):
        ts, id = a[i]
        cnt[id] += 1
        while ts - a[j][0] >= d:
            cnt[a[j][1]] -= 1
            j += 1
            
        if cnt[id] >= k: ans.add(id)
    for x in sorted(ans):
        print(x)


if __name__ == '__main__':
    solve()
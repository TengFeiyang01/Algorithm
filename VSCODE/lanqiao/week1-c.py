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
    n, m = mint()
    a = [ints() for _ in range(n)]
    
    def check(x):
        b = []
        for L, s in a:
            if s <= x:
                low = max(1, L - x + s)
                high = min(m, L + x - s)
                b.append((low, high))

        b.sort()
        if b[0][0] > 1:
            return False

        pre = b[0][1]
        for L, R in b[1:]:
            # pre+1是因为[1,2][3,4]可以合并
            if L > pre + 1:
                return False
            pre = max(pre, R)
        return pre == m


    l, r = 1, 1000000000
    while l < r:
        mid = l + r >> 1
        if check(mid):
            r = mid
        else:
            l = mid + 1

    print(r)

if __name__ == '__main__':
    solve()
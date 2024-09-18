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
    a = [ints() for i in range(n)]
    a.sort()
    b = []
    
    for l, r in a:
        if not b or b[-1][1] < l:
            b.append([l, r])
        else:
            b[-1][1] = max(b[-1][1], r)
    print(len(b))

if __name__ == '__main__':
    solve()
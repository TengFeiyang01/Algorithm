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

from collections import Counter

def solve() -> None:
    s = input()
    n = len(s)
    cnt = Counter(s)
    ans = [None] * n
    i = 0
    for k, v in sorted(cnt.items(), key=lambda x: -x[1]):
        if v > (n + 1) // 2:
            ans = []
            break
        for j in range(v):
            ans[i] = k
            i += 2
            if i >= n:
                i = 1
    print("".join(ans))


if __name__ == '__main__':
    solve()
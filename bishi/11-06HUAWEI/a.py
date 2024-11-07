import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache
from math import *
from collections import *


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


def solve() -> None:
    n = sint()
    cnt = Counter()
    
    for x in ints():
        if x - 1 in cnt:
            cnt[x - 1] -= 1
            if cnt[x - 1] == 0:
                del cnt[x - 1]
        cnt[x] += 1
    print(sum(cnt.values()))

if __name__ == '__main__':
    solve()
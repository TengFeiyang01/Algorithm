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

def getMaximumTasks(limit, primary, secondary):
    secondary.sort()
    ans = 0
    a = [limit - x for x in primary]
    a.sort()
    i = j = 0
    n = len(a)
    while i < n:
        if a[i] >= secondary[j]:
            ans += 1
            j += 1
        i += 1
    return ans
    
def solve() -> None:
    print(getMaximumTasks(sint(), ints(), ints()))


if __name__ == '__main__':
    solve()
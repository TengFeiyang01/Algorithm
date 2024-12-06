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


def getMaximumOperations(s):
    ans = 0
    n = len(s)
    last = {}
    for i in range(n - 3, -1, -1):
        if s[i] == s[i + 1] and s[i] != s[i + 2]:
            if s[i] not in last:
                ans += n - i - 2
                last = {}
            else:
                ans += last[s[i]] - i - 2
            last[s[i]] = i
    return ans
def solve() -> None:
    print(getMaximumOperations(input()))

if __name__ == '__main__':
    solve()
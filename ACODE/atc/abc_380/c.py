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
    n, k = mint()
    s = list(input())
    cnt = i = j = 0
    while i < n:
        if s[i] == '1':
            while i < n and s[i] == '1':
                if cnt == k - 1:
                    s[i], s[j] = s[j], s[i]
                    j += 1
                i += 1
            j = i
            cnt += 1
        else:
            i += 1
    print("".join(s))            


if __name__ == '__main__':
    solve()
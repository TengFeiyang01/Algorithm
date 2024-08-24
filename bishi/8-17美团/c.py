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
    n = int(input())
    a = list(map(int, input().split()))
    s = sum(a)
    k = s % n
    d = s // n
    a.sort(reverse=True)
    ans = 0
    b = [d + 1] * k + [d] * (n - k)
    for x, y in zip(a, b):
        ans += abs(x - y)
    print(ans // 2)
            
            
        

if __name__ == '__main__':
    solve()
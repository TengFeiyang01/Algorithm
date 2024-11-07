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
    x, y = mint()
    s = input()
    ans = 0
    a, b, c = s.count('A'), s.count('B'), s.count('C')
    for i in range(min(b, c)+1):
        ans = max(ans, min(a, b-i)*x+i*y)
    print(ans)

if __name__ == '__main__':
    solve()
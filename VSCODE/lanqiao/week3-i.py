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
    n, m, x = mint()
    a = ints()
    b = ints()
    i, j = 0, m - 1

    ans = 0
    while i < n and j >= 0:
        if a[i] + b[j] > x: j -= 1
        elif a[i] + b[j] < x: i += 1
        else:
            ans += 1
            print(i, j)
            break

    
    

if __name__ == '__main__':
    solve()
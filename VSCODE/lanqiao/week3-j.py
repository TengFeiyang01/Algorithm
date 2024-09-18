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
    a = ints()
    b = ints()
    i = 0
    for x in b:
        if x == a[i]:
            i += 1
            if i == n:
                print("Yes")
                return
    print("No")
    

if __name__ == '__main__':
    solve()
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
    a = ints()
    b = ints()
    for i in range(n):
        b[i] = a[i] - b[i]
    b.append(0)
    
    for i in range(n, 0, -1):
        b[i] -= b[i - 1]
    
    print(sum(max(x, 0) for x in b))



if __name__ == '__main__':
    solve()
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


def solve1():
    encoded = list(map(int, input().split(',')))
    n = len(encoded)
    s = 0
    for i in range(0,n,2):
        s ^= encoded[i]
    for i in range(n+1):
        s ^= i + 1
    res = [0] * n + [s]
    for i in range(n-1, -1, -1):
        res[i] = res[i + 1] ^ encoded[i]
    ans = [str(x) for x in res]
    print(",".join(ans))

def solve() -> None:
    a = list(map(int, input().split(',')))
    """
      6 5 4 6
    2 4 1 5 3

      3 1 7
    1 2 3 4

    """
    
    s = 0
    n = len(a) + 1
    for i in range(1, n+1):
        s ^= i
    for x in a[::2]:
        s ^= x
    ans = [s]
    
    for x in a[::-1]:
        s ^= x
        ans.append(s)
    ans = [str(x) for x in ans]
    print(",".join(ans[::-1]))

if __name__ == '__main__':
    solve1()
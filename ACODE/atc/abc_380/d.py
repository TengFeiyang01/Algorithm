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
    s = list(input())
    q = int(input())
    n = len(s)
    for k in ints():
        f = False
        p = n
        while k > p:
            p *= 2
        while k > n:
            if k > p // 2:
                k -= p // 2
                f = not f
            p = p // 2
        k -= 1
        if f:
            if s[k] >= 'A' and s[k] <= 'Z':
                print(chr(ord(s[k]) - ord('A') + ord('a')), end=' ')
            else:
                print(chr(ord(s[k]) - ord('a') + ord('A')), end=' ')
        else:
            print(s[k], end=' ')



if __name__ == '__main__':
    solve()
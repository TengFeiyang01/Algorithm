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
    a = list(input().split())
    for i in range(n):
        if a[i] == 'J':
            a[i] = '11'
        elif a[i] == 'Q':
            a[i] = '12'
        elif a[i] == 'K':
            a[i] = '13'
        elif a[i] == 'A':
            a[i] = '1'
    for i in range(n):
        a[i] = int(a[i])-1
    a.sort()
    a = a + a
    for i in range(n):
        ok = True
        for j in range(1, n):
            if (a[i + j] + 13 - a[i + j - 1]) % 13 != 1:            
                ok = False
        if ok:
            print("Yes")
            return
    print("No")
            
if __name__ == '__main__':
    solve()
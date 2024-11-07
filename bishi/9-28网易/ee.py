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

def getMinSize(gameSize, k):
    l, r = max(gameSize), 10**13
    gameSize.sort(reverse=True)
    def check(x):
        cnt = 0
        i, j = 0, len(gameSize)-1
        while i <= j:
            if gameSize[i] + (gameSize[j] if i != j else 0) <= x:
                j -= 1
            i += 1
            cnt += 1
        return cnt <= k
    
    while l < r:
        mid = l + r >> 1
        if check(mid):
            r = mid
        else:
            l = mid + 1        
    return l

def solve() -> None:
    print(getMinSize(ints(), sint()))

if __name__ == '__main__':
    solve()
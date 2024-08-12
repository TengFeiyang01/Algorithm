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

def solution(fish, baits):
    baits.sort()
    fish.sort()
    n = len(fish)
    j = 0
    ans = 0
    for x in baits:
        cnt = 0
        while j < n and fish[j] <= x:
            j += 1
        while j < n and fish[j] > x and cnt < 3:
            cnt += 1
            j += 1
        
        ans += cnt
    print(ans)
    

def solve() -> None:
    solution(ints(), ints())

if __name__ == '__main__':
    solve()
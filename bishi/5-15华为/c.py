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
    nums = ints()
    
    root = nums[0]
    node = i = 0
    
    adj = [[] for _ in range]
    i += 1
    while i < n:
        if nums[i] == -1:
            
    

if __name__ == '__main__':
    solve()
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
    a = []
    while n:
        a.append(n % 3)
        n //= 3
    ans = []
    for i, x in enumerate(a):
        for j in range(2):
            if x >> j & 1:
                ans.append(3 ** i * 2 ** j)
    print(len(ans))
    print(*ans[::-1])

        
        

if __name__ == '__main__':
    for _ in range(sint()):
        solve()
    
    
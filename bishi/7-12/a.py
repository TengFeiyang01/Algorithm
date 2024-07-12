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
    def primeFactorization(x):
        if x % 1 != 0:
            return []
        ans = []
        i = 2
        while i * i <= x:
            while x % i == 0:
                ans.append(i)
                x //= i
            i += 1
        if x > 1:
            ans.append(x)
        return ans
    
    print(primeFactorization(1024*27*125))
    print(primeFactorization(1.3))

if __name__ == '__main__':
    solve()
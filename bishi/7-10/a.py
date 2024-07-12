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
    a ,b = mint()
    
    def solution(A, B):
        x = int(A ** 0.5)
        ans = 0
        if x * (x + 1) < A:
            x += 1
        while x * (x + 1) <= B:
            ans += 1
            x += 1
        return ans
    
    print(solution(a, b))
        

if __name__ == '__main__':
    solve()
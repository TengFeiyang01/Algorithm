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

def solution(numbers):
    ans = 0
    if len(numbers) <= 2:
        print(ans)
        return
    p, q = numbers[0], numbers[1]
    for x in numbers[2:]:
        if x != p and x != q:
            ans += 1
    # return ans
    print(ans)

def solve() -> None:
    solution(ints())

if __name__ == '__main__':
    solve()
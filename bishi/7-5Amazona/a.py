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
    power = ints()
    
    n = len(power)
    ans = 0
    for i in range(1, n):
        if power[i] < power[i - 1]:
            ans += power[i - 1] - power[i]
    return ans


    print(ans)
    


if __name__ == '__main__':
    solve()
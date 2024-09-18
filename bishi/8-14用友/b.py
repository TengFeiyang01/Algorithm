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
    n = int(input())
    a = [0] + list(map(int, input().split()))
    odd = [0] * (n + 2)
    even = [0] * (n + 2)
    ans = sum(a)
    for i in range(1, n+1):
        if i % 2:
            odd[i] = a[i]
        else:
            even[i] = a[i]
        odd[i] += odd[i - 1]
        even[i] += even[i - 1]
        
    ans = abs(odd[n] - even[n])
    
    for i in range(1, n+1):
        ans = min(ans, abs(odd[i - 1] + even[n] - even[i] - (even[i - 1] + odd[n] - odd[i])))
    print(ans)

if __name__ == '__main__':
    solve()
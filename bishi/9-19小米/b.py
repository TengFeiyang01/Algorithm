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

def can_make_sorted(a, b):
    n = len(a)
    
    # 尝试使数组 a 递增
    dp_inc = [[False, False] for _ in range(n)]
    dp_inc[0][0] = dp_inc[0][1] = True

    for i in range(1, n):
        dp_inc[i][0] = (dp_inc[i-1][0] and a[i-1] <= a[i]) or \
                       (dp_inc[i-1][1] and b[i-1] <= a[i])
        dp_inc[i][1] = (dp_inc[i-1][0] and a[i-1] <= b[i]) or \
                       (dp_inc[i-1][1] and b[i-1] <= b[i])

    # 尝试使数组 a 递减
    dp_dec = [[False, False] for _ in range(n)]
    dp_dec[0][0] = dp_dec[0][1] = True

    for i in range(1, n):
        dp_dec[i][0] = (dp_dec[i-1][0] and a[i-1] >= a[i]) or \
                       (dp_dec[i-1][1] and b[i-1] >= a[i])
        dp_dec[i][1] = (dp_dec[i-1][0] and a[i-1] >= b[i]) or \
                       (dp_dec[i-1][1] and b[i-1] >= b[i])

    can_sort_a = dp_inc[n-1][0] or dp_inc[n-1][1] or dp_dec[n-1][0] or dp_dec[n-1][1]

    dp_inc_b = [[False, False] for _ in range(n)]
    dp_inc_b[0][0] = dp_inc_b[0][1] = True

    for i in range(1, n):
        dp_inc_b[i][0] = (dp_inc_b[i-1][0] and b[i-1] <= b[i]) or \
                         (dp_inc_b[i-1][1] and a[i-1] <= b[i])
        dp_inc_b[i][1] = (dp_inc_b[i-1][0] and b[i-1] <= a[i]) or \
                         (dp_inc_b[i-1][1] and a[i-1] <= a[i])

    dp_dec_b = [[False, False] for _ in range(n)]
    dp_dec_b[0][0] = dp_dec_b[0][1] = True

    for i in range(1, n):
        dp_dec_b[i][0] = (dp_dec_b[i-1][0] and b[i-1] >= b[i]) or \
                         (dp_dec_b[i-1][1] and a[i-1] >= b[i])
        dp_dec_b[i][1] = (dp_dec_b[i-1][0] and b[i-1] >= a[i]) or \
                         (dp_dec_b[i-1][1] and a[i-1] >= a[i])

    can_sort_b = dp_inc_b[n-1][0] or dp_inc_b[n-1][1] or dp_dec_b[n-1][0] or dp_dec_b[n-1][1]

    return can_sort_a or can_sort_b



def solve() -> None:
    T = int(input())
    for __ in range(T):
        n = int(input())
        a = list(map(int, input().split()))
        b = list(map(int, input().split()))
        print(can_make_sorted(a, b))


if __name__ == '__main__':
    solve()
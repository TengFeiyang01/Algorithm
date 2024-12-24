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

def get(s):
    def f(x):
        return ord(x) - ord('a')
    n = len(s)
    pos = [[] for _ in range(26)]
    for i, x in enumerate(s):
        pos[f(x)].append(i)
    ans = 0
    from bisect import bisect_left, bisect_right
    def check(l, r, arr):
        if arr[0] < l and r > arr[-1] > l:
            return False
        if l < arr[0] < r and arr[-1] > r:
            return False
        return True
            
    for i in range(26):
        for j in range(26):
            if len(pos[i]) == 0 or len(pos[j]) == 0:
                continue
            ok = True
            l1, l2 = pos[i][0], pos[j][0]
            r1, r2 = pos[i][-1], pos[j][-1]
            l = l1
            r = r2
            if l1 <= l2 and r1 <= r2:
                for k in range(26):
                    if k != i and k != j and len(pos[k]) != 0:
                        if not check(l, r, pos[k]):
                            ok = False
                if ok and r - l + 1 != n:
                    ans = max(ans, r - l + 1)

    return ans

def solve() -> None:
    s = input()
    print(get(s))

if __name__ == '__main__':
    solve()
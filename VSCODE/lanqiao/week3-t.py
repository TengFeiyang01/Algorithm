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
    s = input()
    ans = 0
    for i in range(n):
        l = i - 1
        cl = 0
        while l >= 0 and s[i] != s[l]:
            l -= 1
            cl += 1
        r = i + 1
        cr = 0
        while r < n and s[r] != s[i]:
            r += 1
            cr += 1
        ans += cr * cl + max(0, cr - 1) + max(0, cl - 1)
    print(ans) 

if __name__ == '__main__':
    solve()
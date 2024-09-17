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
    k = int(input())
    c = ints()
    t = ints()
    ans = [0] * k
    tot = sum(200 * x for x in c) - sum(t)
    if tot < n:
        print(ans)
        return
    for i in range(n+1):
        s = n
        cur = c[0] + i
        p = (t[0] + i) / (c[0] * 200)
        st = set()
        ok = True
        res = [i]
        s -= i
        for j in range(1,k):
            need = c[j] * 200 * p
            if need < t[j]:
                ok = False
                break
            need -= t[j]
            if s < need:
                ok = False
            else:
                s -= need
                res.append(int(need))
        if s == 0 and ok:
            print(*res)
            return

if __name__ == '__main__':
    solve()
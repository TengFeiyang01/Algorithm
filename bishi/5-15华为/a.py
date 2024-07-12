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
    a = ints()
    stk = []
    for x in a:
        if not stk:
            stk.append(x)
        else:
            n = len(stk)
            s = ok = 0
            for j in range(n - 1, -1, -1):
                s += stk[j]
                if s == x:
                    ok = 1
                    stk = stk[:j] + [2 * x]
            if not ok:
                stk.append(x)
            
    print(*stk[::-1])

if __name__ == '__main__':
    solve()
    





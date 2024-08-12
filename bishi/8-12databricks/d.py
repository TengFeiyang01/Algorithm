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

def solution(queries, diff):
    res = []
    cnt = Counter()
    ans = 0
    for q in queries:
        x = int(q[1:])
        if q[0] == '+':
            cnt[x] += 1
            if x - diff in cnt and x - 2 * diff in cnt:
                ans += cnt[x - diff] * cnt[x - 2 * diff]
            if x + diff in cnt and x + 2 * diff in cnt:
                ans += cnt[x + diff] * cnt[x + 2 * diff]
            if x + diff in cnt and x - diff in cnt:
                ans += cnt[x - diff] * cnt[x + diff]
        else:
            if x - diff in cnt and x - 2 * diff in cnt:
                ans -= cnt[x - diff] * cnt[x] * cnt[x - 2 * diff]
            if x + diff in cnt and x + 2 * diff in cnt:
                ans -= cnt[x + diff] * cnt[x] * cnt[x + 2 * diff]
            if x + diff in cnt and x - diff in cnt:
                ans -= cnt[x - diff] * cnt[x] * cnt[x + diff]
            del cnt[x]
        res.append(ans)
    
    return res

def solve() -> None:
    q = list(input().split())
    dif = sint()
    x = solution(queries=q, diff=dif)
    print(x)
        
if __name__ == '__main__':
    solve()
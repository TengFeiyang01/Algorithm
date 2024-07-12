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
    MX = 20000
    b = [set() for i in range(n)]
    for i in range(n):
        y, x = mint()
        while x < MX:
            b[i].add(x)
            x += y

    ans = inf
    l, r = 0, 1000000
    def check(x):
        cnt = [0] * n
        for i in range(1, MX):
            for j in range(n):
                if i in b[j]:
                    cnt[j] += 1
            if i > x:
                for j in range(n):
                    if i - x in b[j]:
                        cnt[j] -= 1
            if min(cnt) > 0:
                nonlocal ans
                ans = i - x + 1
                return True
        return False           
    
    while l < r:
        mid = l + r >> 1
        if check(mid):
            r = mid
        else:
            l = mid + 1
    print(ans, l)
    
    

if __name__ == '__main__':
    solve()
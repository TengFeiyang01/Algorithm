import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache
from itertools import combinations
from collections import * 
from math import inf


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))

N = 1000001
st = [False] * (N + 1)
primes = []
for i in range(2, N):
    if not st[i]:
        primes.append(i)
    for p in primes:
        if i * p > N: break
        if i % p == 0: break
        st[i * p] = True

def solve() -> None:
    ans = 0
    for x in range(2, N):
        if not st[x]:
            ans += 1
        else:
            x = str(x)
            n = len(x)
            for i in range(1, 1 << n):
                cur = 0
                for j in range(n):
                    if i >> j & 1:
                        cur = cur * 10 + int(x[j])
                if not st[cur]:
                    ans += 1
                    break
        
                
    print(ans)
if __name__ == '__main__':
    solve()
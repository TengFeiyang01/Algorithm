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

def pow(num, n, mod=10**9+7):
    if n == 0: return 1
    elif n % 2 == 1:
        return num * pow(num, n-1, mod) % mod
    else:
        temp = pow(num, n//2, mod)
        return temp * temp % mod
    
def solve() -> None:
    s = input()
    ans = 0
    n = len(s)
    mod = 10 ** 9 + 7
    cnt = Counter(s)
    for c in set(s):
        ans += ((2 ** cnt[c]) - 1) * (2 ** (n - cnt[c])) % mod
        ans %= mod        
    print(ans)

if __name__ == '__main__':
    solve()
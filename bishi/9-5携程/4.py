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


from collections import *
def solve() -> None:
    n, k, s = map(int, input().split())
    a = list(map(int, input().split()))
    
    ans = 0
    tot = sum(a[:k-1])
    
    q = deque([(i, x) for i, x in enumerate(a[:k-1])])
    
    for i in range(k-1, n):
        tot += a[i]
        q.append((i, a[i]))
        while tot > s:
            p, x = q.pop()
            if tot <= s + x:
                q.append((p, x - (tot - s)))
                ans += tot - s
                tot = s
            else:
                tot -= x
                ans += x
        if q and i - q[0][0] + 1 >= k:
            tot -= q.popleft()[1]
    print(ans)

if __name__ == '__main__':
    solve()
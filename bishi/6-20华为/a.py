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


from collections import Counter
def solve() -> None:
    n = int(input())
    k = int(input())
    a = list(map(int, input().split()))

    cnt = Counter()
    i = min(k, n)
    j = 0
    ans = []
    while i <= n:
        now = tuple(a[j:i])
        if now not in cnt:
            cnt[now] = 1
            ans.append(now)
        else:
            cnt[now] += 1
        if i == n:
            break
        j = i
        i = min(i + k, n)
    
    res = []
    for x in ans:
        for y in x:
            res.append(y)
        res.append(cnt[x])
    print(*res)        


if __name__ == '__main__':
    solve()
import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache
from math import inf
from collections import defaultdict


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


def solve() -> None:
    n, m = mint()
    a = ints()
    cnt = defaultdict(list)
    ans = 0
    for i, x in enumerate(a):
        cnt[x].append(i)
        if i and a[i] != a[i - 1]:
            ans += 1
    
    for _ in range(m):
        ops = ints()
        if ops[0] == 1:
            x, y = ops[1], ops[2]
            if x == y:
                continue
            if len(cnt[x]) > len(cnt[y]):
                cnt[x], cnt[y] = cnt[y], cnt[x]
            if not len(cnt[y]): continue

            col = a[cnt[y][0]]

            for p in cnt[x]:
                cnt[y].append(p)
                if p > 0 and a[p - 1] != a[p]:
                    ans -= 1
                if p < n - 1 and a[p + 1] != a[p]:
                    ans -= 1
                a[p] = col
                if p > 0 and a[p - 1] != a[p]:
                    ans += 1
                if p < n - 1 and a[p + 1] != a[p]:
                    ans += 1
            cnt[x].clear()
        else:
            print(ans + 1)

if __name__ == '__main__':
    solve()
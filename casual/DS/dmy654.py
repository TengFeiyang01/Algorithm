import sys

from collections import *
from math import *
from itertools import *
from functools import *
sys.setrecursionlimit(1000000)

input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))

def solve():
    n, m = mint()
    a = ints()
    tr = [inf] * (n << 2)
    cnt = [0] * (n << 2)
    
    def pull(o):
        tr[o] = min(tr[o * 2], tr[o * 2 + 1])
        cnt[o] = 0
        if tr[o] == tr[o * 2]:
            cnt[o] += cnt[o * 2]
        if tr[o] == tr[o * 2 + 1]:
            cnt[o] += cnt[o * 2 + 1]
    
    
    def build(o, l, r):
        if l == r:
            tr[o] = a[l - 1]
            cnt[o] = 1
            return
        mid = l + r >> 1
        build(o * 2, l, mid)
        build(o * 2 + 1, mid + 1, r)
        pull(o)
        

    def modify(o, l, r, x, v):
        if l == r:
            tr[o] = v
            cnt[o] = 1
            return
        mid = l + r >> 1
        if x <= mid:
            modify(o * 2, l, mid, x, v)
        else:
            modify(o * 2 + 1, mid + 1, r, x, v)
        pull(o)
    
    
    def query(o, l, r, x, y):
        if x <= l and r <= y:
            return tr[o], cnt[o]
        mid = l + r >> 1
        mn, count = inf, 0
        if x <= mid:
            lmn, lcnt = query(o * 2, l, mid, x, y)
            if mn > lmn:
                mn, count = lmn, lcnt
            elif mn == lmn:
                count += lcnt
        if y > mid:
            rmn, rcnt = query(o * 2 + 1, mid + 1, r, x, y);
            if mn > rmn:
                mn, count = rmn, rcnt
            elif mn == rmn:
                count += rcnt
        return mn, count
    
    build(1, 1, n)
    
    for i in range(m):
        op, x, y = mint()
        if op == 1:
            modify(1, 1, n, x, y)
        else:
            print(*query(1, 1, n, x, y))
        
if __name__ == '__main__':
    solve()
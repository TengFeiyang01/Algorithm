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
    a = ints()
    left = [-1] * n
    right = [n] * n
    st = []
    for i, x in enumerate(a):
        while st and a[st[-1]] >= x:
            st.pop()
        if st:
            left[i] = st[-1]
        st.append(i)
    st = []
    for i in range(n - 1, -1, -1):
        while st and a[st[-1]] >= a[i]:
            st.pop()
        if st:
            right[i] = st[-1]
        st.append(i)
    ans = 0
    
    for i, x in enumerate(a):
        ans = max(ans, (right[i] - left[i] - 1) * x)
    print(ans)

if __name__ == '__main__':
    solve()
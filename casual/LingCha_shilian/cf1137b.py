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
    s = input()
    t = input()

    cnt = [0] * 2
    for c in s:
        cnt[ord(c) & 1] += 1
    
    pi = [0] * len(t)
    j = 0
    for i in range(1, len(t)):
        v = t[i]
        while j > 0 and t[j] != v:
            j = pi[j - 1]
        if t[j] == v:
            j += 1
        pi[i] = j
    
    ans = []
    j = 0
    while cnt[ord(t[j]) & 1] > 0:
        ans.append(t[j])
        cnt[ord(t[j]) & 1] -= 1
        j += 1
        if j == len(t):
            j = pi[j - 1]
    print("".join(ans)+'0'*cnt[0]+'1'*cnt[1])

if __name__ == '__main__':
    solve()
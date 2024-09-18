import sys

sys.setrecursionlimit(100000)

input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))

from bisect import *
class FenWick:
    def __init__(self, n: int):
        self.n = n
        self.tr = [0 for _ in range(n + 1)]

    def sum(self, i: int):
        i += 1
        s = 0
        while i >= 1:
            s += self.tr[i]
            i &= i - 1
        return s

    def rangeSum(self, l: int, r: int):
        return self.sum(r) - self.sum(l - 1)

    def add(self, i: int, val: int):
        i += 1
        while i <= self.n:
            self.tr[i] += val
            i += i & -i

def arraychallenge(arr):
    n = len(arr)
    b = list(set(arr))
    b.sort()
    ans = []
    tr = FenWick(n + 1)
    cnt = FenWick(n + 1)
    for i, x in enumerate(arr, 1):
        p = bisect_left(b, x) + 1
        big = tr.rangeSum(p + 1, n)
        bigCnt = cnt.rangeSum(p + 1, n)
        small = tr.rangeSum(1, p - 1)
        smallCnt = cnt.rangeSum(1, p - 1)
        ans.append(smallCnt * x - small - (big - bigCnt * x))
        tr.add(p, x)
        cnt.add(p, 1)
    return ans



def solve() -> None:
    x = arraychallenge(ints())
    print(x)

if __name__ == '__main__':
    solve()
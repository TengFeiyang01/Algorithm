import sys

from collections import *
from itertools import *
from functools import *
from bisect import*

input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))

MOD = 1000000007


class Factorial:
    def __init__(self, N, mod) -> None:
        N += 1
        self.mod = mod
        self.f = [1 for _ in range(N)]
        self.g = [1 for _ in range(N)]
        for i in range(1, N):
            self.f[i] = self.f[i - 1] * i % self.mod
        self.g[-1] = pow(self.f[-1], mod - 2, mod)
        for i in range(N - 2, -1, -1):
            self.g[i] = self.g[i + 1] * (i + 1) % self.mod

    def fac(self, n):
        return self.f[n]

    def fac_inv(self, n):
        return self.g[n]

    def comb(self, n, m):
        if n < m or m < 0 or n < 0: return 0
        return self.f[n] * self.g[m] % self.mod * self.g[n - m] % self.mod

    def permu(self, n, m):
        if n < m or m < 0 or n < 0: return 0
        return self.f[n] * self.g[n - m] % self.mod

    def catalan(self, n):
        return (self.comb(2 * n, n) - self.comb(2 * n, n - 1)) % self.mod

    def inv(self, n):
        return self.f[n - 1] * self.g[n] % self.mod

def solve():
    n, m, q = mint()
    R = ints()
    C = ints()
    cntR = defaultdict(int)
    cntC = defaultdict(int)
    for x in R: cntR[x] += 1
    for x in C: cntC[x] += 1

    r = list(sorted(set(R)))
    c = list(sorted(set(C)))
    
    pr = [0] * len(cntR)
    pc = [0] * len(cntC)


    for i, (x, y) in enumerate(sorted(cntR.items())):
        pr[i] = y
        if i: pr[i] *= pr[i - 1]


    for i, (x, y) in enumerate(sorted(cntC.items())):
        pc[i] = y
        if i: pc[i] *= pc[i - 1]


    Comb = Factorial(200010, MOD)
    
    for i in range(q):
        x1, y1, x2, y2 = mint()
        x1 -= 1
        x2 -= 1
        y1 -= 1
        y2 -= 1

        ri, rj = bisect_left(r, R[x2]), bisect_left(r, R[x1])
        ci, cj = bisect_left(c, C[y2]), bisect_left(c, C[y1])

        if x1 == x2:
            if C[y1] >= C[y2]:
                print(0)
            else:
                print(pc[ci - 1] // pc[cj])
        elif y1 == y2:
            if R[x1] >= R[x2]:
                print(0)
            else:
                print(pr[ri - 1] // pr[ci])
        else:
            lx = ri - rj
            ly = ci - cj

            x = pc[ci - 1] // pc[cj]
            y = pr[ri - 1] // pr[ci]
            print(x * y * Comb.comb(lx + ly, lx))


if __name__ == '__main__':
    solve()


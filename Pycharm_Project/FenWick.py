# 左闭右开 0base
class Fenwick:
    def __init__(self, n=0):
        self.n = n
        self.a = [0] * n

    def add(self, x, v):
        i = x + 1
        while i <= self.n:
            self.a[i - 1] += v
            i += i & -i

    def sum(self, x):
        ans = 0
        i = x
        while i > 0:
            ans += self.a[i - 1]
            i -= i & -i
        return ans

    def range_sum(self, l, r):
        return self.sum(r) - self.sum(l)

    def select(self, k):
        x = 0
        cur = 0
        i = 1 << (self.n.bit_length() - 1)
        while i > 0:
            if x + i <= self.n and cur + self.a[x + i - 1] <= k:
                x += i
                cur += self.a[x - 1]
            i //= 2
        return x

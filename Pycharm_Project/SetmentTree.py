class SegmentTree:
    def __init__(self, n, P):
        self.n = n
        self.P = P
        self.tag = [1] * (4 * n)
        self.sum = [0] * (4 * n)

    def pull(self, p):
        self.sum[p] = (self.sum[2 * p] + self.sum[2 * p + 1]) % self.P

    def mul(self, p, v):
        self.tag[p] = self.tag[p] * v % self.P
        self.sum[p] = self.sum[p] * v % self.P

    def push(self, p):
        self.mul(2 * p, self.tag[p])
        self.mul(2 * p + 1, self.tag[p])
        self.tag[p] = 1

    def query(self, p, l, r, x, y):
        if l >= y or r <= x:
            return 0
        if l >= x and r <= y:
            return self.sum[p]
        m = (l + r) // 2
        self.push(p)
        return (self.query(2 * p, l, m, x, y) + self.query(2 * p + 1, m, r, x, y)) % self.P

    def query_range(self, x, y):
        return self.query(1, 0, self.n, x, y)

    def range_mul(self, p, l, r, x, y, v):
        if l >= y or r <= x:
            return
        if l >= x and r <= y:
            return self.mul(p, v)
        m = (l + r) // 2
        self.push(p)
        self.range_mul(2 * p, l, m, x, y, v)
        self.range_mul(2 * p + 1, m, r, x, y, v)
        self.pull(p)

    def range_mul_update(self, x, y, v):
        self.range_mul(1, 0, self.n, x, y, v)

    def add(self, p, l, r, x, v):
        if r - l == 1:
            self.sum[p] = (self.sum[p] + v) % self.P
            return
        m = (l + r) // 2
        self.push(p)
        if x < m:
            self.add(2 * p, l, m, x, v)
        else:
            self.add(2 * p + 1, m, r, x, v)
        self.pull(p)

    def add_update(self, x, v):
        self.add(1, 0, self.n, x, v)

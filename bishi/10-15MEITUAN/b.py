import sys
from math import *


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


# 判断是否是质数的函数
def is_prime(x):
    if x < 2:
        return False
    for i in range(2, int(sqrt(x)) + 1):
        if x % i == 0:
            return False
    return True

class KM:
    def __init__(self, n):
        self.n = n
        self.match = [-1] * n
        self.lx = [0] * n
        self.ly = [0] * n
        self.slack = [float('inf')] * n
        self.vis_x = [False] * n
        self.vis_y = [False] * n
        self.weight = [[0] * n for _ in range(n)]

    def add_edge(self, u, v, w):
        self.weight[u][v] = w

    def find(self, x):
        self.vis_x[x] = True
        for y in range(self.n):
            if self.vis_y[y]:
                continue
            t = self.lx[x] + self.ly[y] - self.weight[x][y]
            if t == 0:
                self.vis_y[y] = True
                if self.match[y] == -1 or self.find(self.match[y]):
                    self.match[y] = x
                    return True
            else:
                self.slack[y] = min(self.slack[y], t)
        return False

    def km(self):
        for i in range(self.n):
            self.lx[i] = max(self.weight[i])
        
        for x in range(self.n):
            self.slack = [float('inf')] * self.n
            while True:
                self.vis_x = [False] * self.n
                self.vis_y = [False] * self.n
                if self.find(x):
                    break
                d = float('inf')
                for i in range(self.n):
                    if not self.vis_y[i]:
                        d = min(d, self.slack[i])
                for i in range(self.n):
                    if self.vis_x[i]:
                        self.lx[i] -= d
                    if self.vis_y[i]:
                        self.ly[i] += d
                    else:
                        self.slack[i] -= d
        
        result = 0
        for y in range(self.n):
            if self.match[y] != -1:
                result += self.weight[self.match[y]][y]
        return result

def pet_battle(n, a, m, b):
    size = max(n, m)
    km = KM(size)
    
    for i in range(n):
        for j in range(m):
            if is_prime(a[i]) and is_prime(b[j]):
                km.add_edge(i, j, 2 * (a[i] + b[j]))
            elif is_prime(a[i]) or is_prime(b[j]):
                km.add_edge(i, j, 2 * max(a[i], b[j]))
            else:
                km.add_edge(i, j, a[i] + b[j])

    print(km.km())
    # 输出与a对战的b的编号
    result = []
    reverse_match = [-1] * size
    for y in range(size):
        if km.match[y] != -1:
            reverse_match[km.match[y]] = y

    for i in range(n):
        if reverse_match[i] < m and reverse_match[i] != -1:
            result.append(reverse_match[i] + 1)
        else:
            result.append(-1)
    print(*result)

n, m = mint()
a = ints()
b = ints()
pet_battle(n, a, m, b)
import sys

from math import inf

input = sys.stdin.readline


def solve():
    n, k = map(int, input().split())
    x, y = map(int, input().split())
    a = []
    for _ in range(n):
        xi, yi, level = map(int, input().split())
        a.append((level, xi, yi))
    a.sort()

    def L2(x1, y1, x2, y2):
        return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) ** 0.5

    d0 = [L2(x, y, x1, y1) for _, x1, y1 in a]
    d1 = [L2(a[i][1], a[i][2], a[i + 1][1], a[i + 1][2]) for i in range(n - 1)]

    f = [[inf] * k for _ in range(n)]
    f[0][k - 1] = d0[0]
    for i in range(1, n):
        f[i][k - 1] = min(f[i - 1]) + d0[i - 1] + d0[i]
        for j in range(k - 1):
            f[i][j] = f[i - 1][j + 1] + d1[i - 1]

    print(round(min(f[-1]) + d0[-1], 1))


if __name__ == '__main__':
    solve()
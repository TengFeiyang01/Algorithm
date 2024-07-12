# E:\0CODE\casual\LingCha_shilian\CF1065C.py 2024-04-19 by ytf
import sys

sys.setrecursionlimit(100000)

input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


def solve() -> None:
    n, k = mint()
    a = ints()
    a.sort(reverse=True)
    ans = s = 0

    for i in range(1, n):
        d = a[i - 1] - a[i]
        if d * i + s < k:
            s += d * i
            continue
        d -= (k - s) // i
        ans += 1 + d // (k // i)
        s = d % (k // i) * i
    if s > 0:
        ans += 1
    print(ans)



if __name__ == '__main__':
    solve()
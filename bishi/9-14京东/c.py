import sys

sys.setrecursionlimit(100000)

input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


def solve() -> None:
    n = int(input())
    a = ints()
    tot = sum(a)
    pre = 0
    ans = 10000000000
    for i in range(n-1):
        tot -= a[i]
        pre += a[i]
        ans = min(ans, pre * tot)
    print(ans)

if __name__ == '__main__':
    solve()
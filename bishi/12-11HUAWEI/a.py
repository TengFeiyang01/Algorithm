import sys

input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


def solve() -> None:
    n = sint()
    a = ints()
    ans = sum(a)
    cur = 0
    tot = sum(a)
    l, r = 0, 0
    while r < n:
        tot -= a[r]
        cur += a[r]

        while cur * 6 >= tot:
            ans = min(ans, cur * 6)
            cur -= a[l]
            tot += a[l]
            l += 1
        ans = min(ans, tot)
        r += 1
    print(ans)



if __name__ == '__main__':
    solve()
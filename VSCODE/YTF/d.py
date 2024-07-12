import sys

input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


def solve():
    n, m = mint()
    a = [0] * (n + 2)
    b = []
    for i in range(m):
        l, r = mint()
        b.append([l, r])
        a[l] += 1
        a[r + 1] -= 1
    
    cnt = [0] * (n + 1)
    
    res = 0

    for i in range(1, n + 1):
        a[i] += a[i - 1]
        if a[i] == 1:
            cnt[i] += 1
        cnt[i] += cnt[i - 1]
        if a[i] == 0:
            res += 1
    
    for l, r in b:
        print(res + cnt[r] - cnt[l - 1])


if __name__ == '__main__':
    solve()

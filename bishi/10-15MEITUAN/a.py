def solve() -> None:
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))
    ans = sum(c)
    d = [0] * (m + 1)
    for x, y, z in zip(a, b, c):
        d[x] = max(d[x], y - z)
    for p in set(a):
        ans += d[p]
    print(ans)
    


if __name__ == '__main__':
    solve()
import sys



def solve() -> None:
    n = int(input())
    a = list(map(int, input().split()))
    l, r = 0, n - 1
    ans = 0
    while l < r:
        d = abs(a[l] - a[r])
        ans += d
        if a[l] > a[r] and r > 0:
            a[r] -= d
            a[r - 1] -= d
        elif a[l] < a[r] and l < n - 1:
            a[l] += d
            a[l + 1] += d
        l += 1
        r -= 1
    for i in range(n // 2):
        if a[i] != a[n - i - 1]:
            print(-1)
            return
    print(ans)

if __name__ == '__main__':
    solve()
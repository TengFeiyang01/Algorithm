def solve():
    n = int(input())
    s = [0] * (n + 1)

    a = list(map(int, input().split()))
    for i in range(1, n + 1):
        x = a[i - 1]
        if x:
            s[i] = s[i - 1] + 1
        else:
            s[i] = s[i - 1] - 1

    p = 0
    q = 0
    a = 0
    b = 0

    for i in range(1, n + 1):
        a = max(a, s[i] - p)
        p = min(p, s[i])
        b = min(b, s[i] - q)
        q = max(q, s[i])

    x = s[n] - a * 2
    y = s[n] - b * 2

    if x >= 0:
        print((x - y) // 2 + 1)
    elif y <= 0:
        print((x - y) // 2 + 1)
    else:
        z = max(abs(x), abs(y))
        if y % 2:
            print((z + 1) // 2)
        else:
            print(z // 2 + 1)

if __name__ == "__main__":
    solve()

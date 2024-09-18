
def solve():
    n = int(input())
    s = input()
    f = [[0, 0], [0, 0]]
    f[0][0] = 1
    ans = 0
    x = 0
    for i in range(n):
        if s[i] == '0':
            ans += f[i & 1][x & 1]
        else:
            ans += f[i & 1][(x + 1) & 1]
        if i < n - 1 and s[i] != s[i + 1]:
            x += 1
        f[(i + 1) % 2][x % 2] += 1
    print(ans)


solve()
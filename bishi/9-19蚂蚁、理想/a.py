import math

mod = int(1e9 + 7)
maxn = int(2e5 + 10)

n, k = map(int, input().split())
s = [0] + list(map(int, input().split()))

dp = [[[0 for _ in range(60)] for _ in range(110)] for _ in range(n + 1)]

dp[1][s[1]][1] = s[1]

for i in range(2, n + 1):
    for j in range(1, 101):
        g = math.gcd(j, s[i])
        for l in range(1, k + 1):
            if dp[i - 1][j][l - 1]:
                dp[i][s[i]][l] = max(dp[i][s[i]][l], dp[i - 1][j][l - 1] + s[i])
            if dp[i - 1][j][l]:
                dp[i][g][l] = max(dp[i][g][l], dp[i - 1][j][l] - j + g)

ans = 0
for i in range(1, 101):
    ans = max(ans, dp[n][i][k])

print(ans)

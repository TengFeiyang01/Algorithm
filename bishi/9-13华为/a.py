def solve():
    n = int(input())
    k = int(input()) 
    a = list(map(int, input().split()))
    B = int(input())
    M = int(input())

    inf = float('inf')
    dp = [[inf] * (M + 1) for _ in range(n + 1)]
    dp[0][0] = 0

    for i in range(1, n + 1):
        for j in range(M + 1):
            dp[i][j] = dp[i - 1][j] + a[i - 1]
            if j > 0:
                for p in range(i - 1, max(0, i - k) - 1, -1):
                    dp[i][j] = min(dp[i][j], dp[p][j - 1] + B * (i - p))

    ans = min(dp[n][j] for j in range(M + 1))
    print(ans)

if __name__ == "__main__":
    solve()

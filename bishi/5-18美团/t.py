n, k = map(int, input().split())
dp = [0] * (k + 1)
s = [0] * (k + 1)
dp[0] = 1
for i in range(1, n - 1):
    for j in range(1, k + 1):
        dp[j] = s[j] if j < i else (s[j] - s[j - i])
    for j in range(0, k + 1):
        s[j] = (0 if j == 0 else s[j - 1]) + dp[j]
ans = 0
for i in range(1, k + 1):
    dp[i] += dp[i - 1]
for i in range(1, n + 1):
    for j in range(i + 1, n + 1):
        if i == j: continue
        cur = i + j - 3
        if cur <= k:
            ans += dp[k - cur]
print(ans)                    

def count_modules(n):
    MOD = 10**9 + 7
    
    dp = [[0] * 2 for _ in range(n + 1)]
    
    dp[2][0] = 1  # TI -> T
    dp[2][1] = 1  # TI -> I
    
    for i in range(3, n + 1):
        dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % MOD  # T
        dp[i][1] = dp[i-1][0] % MOD                # I

    return (dp[n][0] + dp[n][1]) % MOD

# 输入处理
T = int(input())
for _ in range(T):
    n = int(input())
    result = count_modules(n)
    print(result)

def count_ways(n, m, q, t, d):
    MOD = 10**9 + 7
    
    # 统计优先玩家和普通玩家
    priority_count = 0
    normal_count = 0
    
    for days in d:
        if days > t:
            priority_count += 1
        else:
            normal_count += 1
            
    # 米小游是否是优先玩家
    if n > t:
        priority_count += 1
    else:
        normal_count += 1
    
    # 动态规划数组
    dp = [[0] * (m + 1) for _ in range(priority_count + 1)]
    dp[0][0] = 1
    
    # 动态规划计算排列方式
    for i in range(1, priority_count + 1):
        for j in range(m + 1):
            dp[i][j] = dp[i - 1][j]
            if j > 0:
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD
    
    result = 0
    
    for k in range(1, min(priority_count, m) + 1):
        remaining_priority = priority_count - k
        remaining_normal = normal_count
        
        if remaining_priority <= m and remaining_priority + remaining_normal >= m:
            result = (result + dp[priority_count - 1][k - 1]) % MOD
    
    return result

# 示例输入
n = 2
m = 1
q = 2
t = 1
d = [1, 2]

# 调用函数并输出结果
print(count_ways(n, m, q, t, d))
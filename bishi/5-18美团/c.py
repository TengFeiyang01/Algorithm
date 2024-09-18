def solve():
    import sys
    input = sys.stdin.read
    s = input().strip()
    
    dp = [[0] * 4 for _ in range(26)]
    res = 0
    
    for c in s:
        if c in 'aeiou':
            continue
        else:
            p = ord(c) - ord('a')
            for j in range(3, 1, -1):
                dp[p][j] = 0
                for k in range(26):
                    dp[p][j] = dp[p][j] + dp[k][j-1]
            dp[p][1] = 1
    
    for i in range(26):
        for j in range(2, 4):
            res = res + dp[i][j]
    
    print(res)

if __name__ == '__main__':
    solve()

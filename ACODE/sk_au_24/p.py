def count_modules(n, A, B, C, D):
    MOD = 10**9 + 7
    
    dp = [0] * (n + 1)
    
    dp[1] = 2  
    if n > 1:
        dp[2] = 4 

    for i in range(3, n + 1):
        dp[i] = (dp[i - 1] * 2 + dp[i - 2] * 4) % MOD
    print(dp)
    return dp[n]

def main():
    T = int(input())
    for _ in range(T):
        n = int(input())
        A = input().strip()
        B = input().strip()
        C = input().strip()
        D = input().strip()
        
        result = count_modules(n, A, B, C, D)
        print(result)

if __name__ == "__main__":
    main()

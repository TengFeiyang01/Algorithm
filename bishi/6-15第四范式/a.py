import sys
import itertools

INF = float('inf')

def solve():
    n = int(input())
    dp = [[INF] * 5001 for _ in range(n + 1)]
    dp[0][0] = 0
    
    for i in range(1, n + 1):
        x = int(input())
        for j in range(5001):
            if j >= x:
                dp[i][j] = min(dp[i][j], dp[i - 1][j - x] + x)
            if j + 100 <= 5000:
                dp[i][j + x] = min(dp[i][j + x], dp[i - 1][j + 100 ])
    
    print(min(dp[-1]))

def main():
    
    t = int(input())
    index = 1
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
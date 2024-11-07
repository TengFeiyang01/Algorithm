
def solve() -> None:
    mod = 10**9 + 7
    m, k = map(int, input().split())
    f = [1] + [0] * k
    n = m - 2
    for i in range(1, n + 1):
        g = [0] * (k + 1)
        for j in range(k + 1):
            g[j] = (g[j - 1] if j - 1 >= 0 else 0) - (f[j - i] if j - i >= 0 else 0) + f[j]
            g[j] %= mod
        f = g

    ans = 0
    for i in range(1, k+1):
        f[i] += f[i - 1]
    
    for i in range(1, m):
        for j in range(i+1, m+1):
            if i + j - 3 <= k:
                ans += f[k-(i + j - 3)]
    print(ans%mod)
    
    

if __name__ == '__main__':
    solve()
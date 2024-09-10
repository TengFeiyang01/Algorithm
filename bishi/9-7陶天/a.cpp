#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

const int N = 1000002;
const int mod = 1000000007;

i64 fac[N], infac[N];

int qmi(i64 a, i64 b) {
    i64 res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res % mod;
}

void init() {
    fac[0] = infac[0] = 1;
    for (int i = 1; i < N; ++i) {
        fac[i] = fac[i - 1] * i % mod;
        infac[i] = infac[i - 1] * qmi(i, mod - 2) % mod;
    }
}

i64 C(int a, int b) {
	return fac[a] * infac[b] % mod * infac[a - b] % mod;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    i64 s = 0;
    // 先枚举组数 然后处理
    std::vector<i64> dp(N);
    dp[0] = dp[1] = 1;

    for (int i = 1; i < n; ++i) {
    	s += a[i];
    	std::vector<i64> ndp(N);
    	for (int j = 0; j < N; ++j) {
    		// ndp[i]
    	}
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}

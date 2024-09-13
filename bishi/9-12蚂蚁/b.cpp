#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

constexpr int mod = 1000000007;
int qpow(i64 x, i64 y) {
    i64 res = 1;
    for (; y; y /= 2, x = x * x % mod)
        if (y & 1)
            res = res * x % mod;
    return res;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> fac(n + 1);
    std::string s;
    std::cin >> s;
    std::map<int, int> cnt;
    for (auto c : s) {
    	cnt[c]++;
    }
    int odd = 0, tot = 0;
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
    	fac[i] = fac[i - 1] * i % mod;
    }
    i64 ans = 1;

    for (auto [k, v] : cnt) {
    	if (v % 2) {
    		odd++;
    	} 
    	tot += v / 2;
	    ans = ans * qpow(fac[v / 2], mod - 2) % mod;
    }
    if (odd) ans *= odd;
    std::cout << tot << "\n";
    ans = ans * fac[tot] % mod;
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}

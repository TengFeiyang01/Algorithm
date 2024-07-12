#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int mod = 998244353;

void solve() {
    int n, m, k;
    std::cin >> n >> k >> m;
    std::vector<i64> f(n + 2);
    std::vector<std::array<int, 3>> cons(m);
    f[0] = 1;
    for (int i = 0; i < m; ++i) {
    	std::cin >> cons[i][0] >> cons[i][1] >> cons[i][2];
    }
    i64 ans = 1;
    for (int b = 0; b < k; ++b) {
    	std::vector<int> maxL(n + 1), d(n + 2);
    	for (auto [l, r, x] : cons) {
    		if (!(x >> b & 1)) {
    			maxL[r] = std::max(maxL[r], l);
    		} else {
    			d[l]++;
    			d[r + 1]--;
    		}
    	}
    	i64 sumF = 1, sumD = 0, left = 0;
    	for (int i = 1; i <= n + 1; ++i) {
    		while (left < maxL[i - 1]) {
    			sumF -= f[left];
    			left++;
    		}
    		sumD += d[i];
    		if (sumD > 0) {
    			f[i] = 0;
    			continue;
    		}
    		sumF %= mod;
    		f[i] = sumF;
    		sumF *= 2;
    	}
    	ans = ans * f[n + 1] % mod;
    }
    std::cout << (ans + mod) % mod << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}

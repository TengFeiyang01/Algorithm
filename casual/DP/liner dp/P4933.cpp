#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

constexpr int MOD = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    int v = std::ranges::max(a);
    std::vector<i64> g(v + 1);
    std::vector<std::unordered_map<int, i64>> f(n + 1);

    // f[i][d] 以i结尾的 公差为d的方案数 f[i][d] = f[j][d] + 1 //拼在j后面
    i64 ans = n;
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < i; ++j) {
            int d = a[i] - a[j];
    		f[i][d] = (f[i][d] + f[j][d] + 1) % MOD;
    		ans = (ans + f[j][d] + 1) % MOD;
    	}
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}

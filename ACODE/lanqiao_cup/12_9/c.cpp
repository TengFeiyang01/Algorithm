#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<int> dp(1 << 20);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        dp[a[i]]++;
    }

    // 对于每个 ai，存在贡献的数即为自己补集的子集，于是使用高维前缀和计算出来每个集合的贡献，直接计算即可
    
    for (int j = 0; j < 20; ++j) {
        for (int i = 1; i < 1 << 20; ++i) {
            if (i >> j & 1) dp[i] += dp[i ^ (1 << j)];
        }
    }
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += dp[a[i] ^ (1 << 20) - 1];
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}

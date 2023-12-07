#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, c;
    std::cin >> n >> c;
    std::vector<int> a(n);
    std::map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	cnt[a[i]]++;
    }
    std::vector<int> p;
    for (auto [k, v] : cnt) p.push_back(k);
    std::reverse(p.begin(), p.end());
    std::vector<int> dp(c);
    int ans = 0;

    // 从大到小遍历 方便取之后的同余类
    for (int i = 0; i < p.size(); ++i) {
        int x = p[i];
        int f = cnt[p[i]];
        if (dp[(x + 1) % c]) {
            f += dp[(x + 1) % c];
            dp[x % c] = f;
        } else {
            dp[x % c] = f;
        }
        ans = std::max(ans, dp[x % c]);
    }
    
    std::cout << n - ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}

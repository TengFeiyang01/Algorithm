#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    std::map<i64, int> cnt;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	cnt[a[i]]++;
    }
    
    std::sort(a.begin(), a.end());
    if (cnt[a[0]] == n or cnt[a[0]] == 1) {
    	std::cout << n - 1 << "\n";
    	return;
    }

    // 答案1：最小值全在x中
    int ans = n - cnt[a[0]];
    std::vector<int> g(n);
    g[n - 2] = a[n - 1] - a[n - 2];
    
    for (int i = n - 3; i >= 0; --i) {
        g[i] = std::__gcd(g[i + 1], a[i + 1] - a[i]);
    }
    
    auto lcm = [&](i64 x, i64 y) -> i64 {
        return x / std::__gcd(x, y) * y;
    }; 
    
    std::vector<i64> pre{a[0]};
    for (int i = 1; i < n and lcm(pre[i - 1], a[i]) <= a[n - 1]; ++i) {
        pre.push_back(lcm(pre[i - 1], a[i]));
    }
    
    int m = pre.size();
    
    for (int i = 1; i < n and i <= m; ++i) {
        if (g[i] % pre[i - 1] == 0) {
            ans = std::max(ans, i + 1);
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

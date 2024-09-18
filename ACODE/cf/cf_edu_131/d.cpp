#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    std::vector<std::pair<std::vector<int>, std::vector<int>>> q;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }

    q.push_back({a, b});

    int ok = 0;
    int ans = 0;
    for (int i = 29; i >= 0; --i) {
        auto t = q;
        q.clear();
        for (auto p : t) {
            std::vector<std::vector<int>> f(2), g(2);
            for (int v : p.first) {
                f[v >> i & 1].push_back(v);
            }
            for (int v : p.second) {
                g[v >> i & 1].push_back(v);
            }
            if (f[0].size() != g[1].size()) { //当前这一轮无法凑齐 1
                q = t; // 保持不变
                ok = 1;
                break;
            }
            if (f[0].size()) q.push_back({f[0], g[1]});
            if (f[1].size()) q.push_back({f[1], g[0]});
        }
        if (ok) {
            ok = 0;
            continue;
        }
        ans |= 1 << i;
    }
    std::cout << ans << "\n";
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

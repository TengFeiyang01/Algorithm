#include <bits/stdc++.h>

using i64 = long long;

constexpr int B = 200;

void solve() {
    int n, q;
    std::cin >> n >> q;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<i64> ans(q);
    std::vector<std::vector<std::array<int, 3>>> ask(n + 1);
    for (int i = 0; i < q; i++) {
        int s, d, k;
        std::cin >> s >> d >> k;
        s--;
        if (d > B) {
            for (int j = 0; j < k; j++) {
                ans[i] += 1LL * (j + 1) * a[s + j * d];
            }
        } else {
            ask[d].push_back({s, k, i});
        }
    }
    
    for (int d = 1; d <= n; d++) {
        if (ask[d].empty()) {
            continue;
        }
        std::vector<i64> s0(n), s1(n);
        for (int i = 0; i < n; i++) {
            if (i >= d) {
                s0[i] = s0[i - d];
                s1[i] = s1[i - d];
            }
            s0[i] += a[i];
            s1[i] += 1LL * a[i] * (i / d);
            for (auto [s, k, j] : ask[d]) {
                i64 res = s1[s + (k - 1) * d];
                if (s >= d) {
                    res -= s1[s - d];
                }
                int coef = 1 - s / d;
                i64 sum0 = s0[s + (k - 1) * d];
                if (s >= d) {
                    sum0 -= s0[s - d];
                }
                res += sum0 * coef;
                ans[j] = res;
            }
        }
    }
    
    for (int i = 0; i < q; i++) {
        std::cout << ans[i] << " \n"[i == q - 1];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
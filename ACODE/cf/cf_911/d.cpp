#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int N = 1e5 + 1;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<std::vector<int>> p(N);
    
    std::ranges::sort(a);

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j * j <= a[i]; ++j) {
            if (a[i] % j == 0) {
                p[j].push_back(i + 1);
                if (a[i] / j != j) p[a[i] / j].push_back(i + 1);
            }
        }
    }
    std::vector<i64> f(N);
    i64 ans = 0;
    int mx = std::ranges::max(a);
    // f[i] GCD 恰好为i的数对的个数
    for (int i = mx; i > 0; --i) {
        f[i] = 0;
        // 这里算出来的是 d, 2d, 3d...
        for (int j = 1; j < p[i].size(); ++j) {
            f[i] += 1LL * j * (n - p[i][j]);
        }
        for (int j = i + i; j <= mx; j += i) {
            f[i] -= f[j];
        }
        ans += i * f[i];
    }
    std::cout << ans << "\n";
}

/*void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::vector<std::vector<int>> factor(N);
    for (int i = 1; i < N; ++i) {
    	for (int j = i; j < N; j += i) {
    		factor[j].push_back(i);
    	}
    }
    std::ranges::sort(a);
    std::vector<i64> cnt(N), f(N);
    i64 ans = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (auto x : factor[a[i]]) {
            f[x] = cnt[x];
        }
    	for (auto x : std::views::reverse(factor[a[i]])) {
            int t = f[x];
            if (t) {
                ans += 1LL * x * t * (n - i - 1);
                for (auto y : factor[x]) {
                    f[y] -= t;
                }
            }
        }
    	for (auto x : factor[a[i]]) {
    		cnt[x]++;
    	}
    }
    std::cout << ans << "\n";
}*/

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}

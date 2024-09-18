#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::array<int, 2>> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i][0] >> a[i][1];
    }
    // 设最大值所处位置为x 最小值必然是 1 或者 m 处取到为0
    // 若区间 [1, >=x] 则选与不选一样 [1, <x] 不选更优 
    auto get = [&](int x) {
        std::map<int, int> cnt;
        int ans = 0, res = 0;
        for (auto [l, r] : a) {
            if (l <= x and r >= x) continue;
            cnt[l]++;
            cnt[r + 1]--;
        }
        for (auto [k, v] : cnt) {
            ans += v;
            res = std::max(ans, res);
        }
        return res;
    };

    
    std::cout << std::max(get(1), get(m)) << "\n";
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
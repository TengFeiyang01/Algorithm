#include <bits/stdc++.h>

using i64 = long long;
constexpr i64 inf = 1e18;
using i128 = __int128;

void solve() {
    int n, q;
    std::cin >> n >> q;
    i128 len = 0;
    std::map<i64, i64> mp;
    // 使用 v 记录操作后长度和操作前长度
    std::vector<std::pair<i64, i64>> v;
    for (int i = 0; i < n; ++i) {
    	i64 op, x;
    	std::cin >> op >> x;
        if (op == 1) {
            len++;
            mp[i64(len)] = x;
        } else {
            if (len > inf) continue;
            
            i64 tmp = len;
            len *= (x + 1);

            if (len > inf) {
                len = inf + 1;
            }
            v.emplace_back(len, tmp);
        }
    }
    std::ranges::sort(v);
    while (q--) {
        i64 x;
        std::cin >> x;
        while (!mp.count(x)) {
            auto it = std::ranges::lower_bound(v, std::pair<i64, i64>{x, 0LL});
            i64 len = (*it).second;
            x %= len;
            if (x == 0) {
                x = len;
            }
        }
        std::cout << mp[x] << " \n"[q == 0];
    }
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

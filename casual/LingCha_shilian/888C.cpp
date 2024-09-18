#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.size(), ans = n;
    std::vector<std::vector<int>> pos(26);
    for (int i = 0; i < n; ++i) {
        pos[s[i] - 'a'].push_back(i);
    }
    for (auto v : pos) {
        if (v.size()) {
            v.push_back(n);
            int pre = -1, now = 0;
            for (auto x : v) {
                now = std::max(x - pre, now);
                pre = x;
            }
            ans = std::min(ans, now);
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

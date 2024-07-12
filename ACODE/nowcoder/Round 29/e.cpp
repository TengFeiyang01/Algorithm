#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = int64_t;

void solve() {
    i64 x;
    std::cin >> x;
    
    if (x == 1) {
        std::cout << "-1\n";
        return;
    }
    
    std::map<i64, int> cnt;
    for (i64 i = 2; i * i <= x; ++i) {
        for (;x % i == 0; x /= i) {
            cnt[i]++;
        }
    }
    if (x > 1) {
        cnt[x] += 1;
    }

    std::vector<i64> ans;
    while (not cnt.empty()) {
        i64 a = 1, b = 0;
        for (auto &[x, y] : cnt) {
            if (not ans.empty() && x == ans.back()) continue;
            if (y > b) {
                std::tie(a, b) = std::pair(x, y);
            }
        }
        if (a == -1) {
            std::cout << -1 << "\n";
            return;
        }
        ans.push_back(a);
        if (!(cnt[a] -= 1)) {
            cnt.erase(a);
        }
    }
 
    std::cout << ans.size() << "\n";
    for (auto x : ans) {
        std::cout << x << " ";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}

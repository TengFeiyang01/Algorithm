#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    --n;
    int len = std::__lg(n) + 1;
    std::cout << len << "\n";
    for (int i = 0; i < len; ++i) {
        std::vector<int> res;
        for (int j = 1; j <= n; ++j) {
            if (j >> i & 1) {
                res.push_back(j);
            }
        }
        std::cout << res.size() << " ";
        for (auto x : res) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
    std::string s;
    std::cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '1') {
            ans |= 1 << i;
        }
    }

    if (ans == 0) {
        std::cout << ++n << "\n";
    } else {
        std::cout << ans << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}



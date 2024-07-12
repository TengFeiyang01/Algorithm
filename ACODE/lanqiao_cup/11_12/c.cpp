#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s, t;
    std::cin >> s >> t;
    std::string p = "3456789XJQKA2MF";

    auto get = [&](std::string ss) {
        int x = 0;
        for (int i = 0; i < 15; ++i) {
            if (ss[0] == p[i] or ss[1] == p[i]) {
                x = i;
            }
        }
        return x;
    };

    if (s[0] == s[1] or s == "MF" or s == "FM") {
        std::cout << "ShallowDream" << "\n";
    } else {
        if (t == "MF" or t == "FM") {
            std::cout << "Joker" << "\n";
        } else if (get(s) >= get(t)) {
            std::cout << "ShallowDream" << "\n";
        } else {
            std::cout << "Joker" << "\n";
        }
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

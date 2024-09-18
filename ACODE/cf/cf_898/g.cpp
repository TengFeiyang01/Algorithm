#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.size();
    int t = std::ranges::count(s, 'A');
    if (t == n) {
        std::cout << "0\n";
        return;
    }
    int duan = 0;
    int mn = inf;
    std::vector<int> pos{-1};
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'B') {
            pos.push_back(i);
        }
    }
    pos.push_back(n);

    for (int i = 1; i < pos.size(); ++i) {
        mn = std::min(mn, pos[i] - pos[i - 1] - 1);
    }

    std::cout << t - mn << "\n";
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
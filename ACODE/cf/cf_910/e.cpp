#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::string s, t;
    std::cin >> s >> t;

    std::array<std::vector<int>, 26> vec;
    for (int i = n - 1; i >= 0; --i) {
        vec[s[i] - 'a'].push_back(i);
    }

    for (int i = 0; i < m; ++i) {
        int x = t[i] - 'a';
        if (vec[x].empty()) {
            std::cout << "NO\n";
            return;
        }
        int p = vec[x].back();
        vec[x].pop_back();
        for (int j = 0; j < x; ++j) {
            while (!vec[j].empty() and vec[j].back() < p) {
                vec[j].pop_back();
            }
        }
    }
    std::cout << "YES\n";
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

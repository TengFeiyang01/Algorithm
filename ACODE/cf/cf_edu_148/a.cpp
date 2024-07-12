#include <bits/stdc++.h>

using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    std::string s;
    std::cin >> s;
    s.erase(s.begin() + s.size() / 2, s.end());
    std::cout << (s == std::string(s.size(), s[0]) ? "NO\n" : "YES\n");
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
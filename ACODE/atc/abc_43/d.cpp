#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.size();
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            std::cout << i + 1 << " " << i + 2 << "\n";
            return;
        }
        if (i + 2 < n and s[i] == s[i + 2]) {
            std::cout << i + 1 << " " << i + 3 << "\n";
            return;
        }
    }
    
    std::cout << "-1 -1\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}

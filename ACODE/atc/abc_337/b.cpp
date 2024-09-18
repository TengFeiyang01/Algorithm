#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int cnt = 0;
    std::string s;
    std::cin >> s;
    std::string t = "ABC";
    int n = s.size();

    for (int a = 0; a <= n; ++a) {
        for (int b = 0; b <= n - a; ++b) {
            int c = n - a - b;
            if (s == std::string(a, 'A') + std::string(b, 'B') + std::string(c, 'C')) {
                std::cout << "Yes" << "\n";
                return;
            }
        }
    }

    std::cout << "No\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}

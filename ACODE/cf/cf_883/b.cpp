#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    std::string s[3];
    std::cin >> s[0] >> s[1] >> s[2];
    for (int i = 0; i < 3; ++i) {
        if (s[i][0] == s[i][1] and s[i][1] == s[i][2] and s[i][0] != '.') {
            std::cout << s[i][0] << "\n";
            return;
        }
    }
    for (int i = 0; i < 3; ++i) {
        if (s[0][i] == s[1][i] and s[1][i] == s[2][i] and s[0][i] != '.') {
            std::cout << s[0][i] << "\n";
            return;
        }
    }

    if (s[0][0] == s[1][1] and s[1][1] == s[2][2] and s[0][0] != '.') {
        std::cout << s[0][0] << "\n";
        return;
    }
    if (s[1][1] == s[0][2] and s[1][1] == s[2][0] and s[1][1] != '.') {
        std::cout << s[1][1] << "\n";
        return;
    }

    std::cout << "DRAW\n";
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

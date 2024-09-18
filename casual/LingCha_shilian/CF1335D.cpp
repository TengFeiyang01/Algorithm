#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::vector<std::string> s(9);
    for (int i = 0; i < 9; ++i) {
    	std::cin >> s[i];
        for (int j = 0; j < 9; ++j) {
            if (s[i][j] == '1') {
                s[i][j] = '2';
            }
        }
        std::cout << s[i] << "\n";
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

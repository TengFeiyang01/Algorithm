#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::string s;
    std::cin >> s;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] != '0') {
            int a = std::stoi(s.substr(0, i));
            int b = std::stoi(s.substr(i));
            if (a < b) {
                std::cout << a << " " << b << "\n";
                return;
            }
        }
    }
    std::cout << "-1\n";

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

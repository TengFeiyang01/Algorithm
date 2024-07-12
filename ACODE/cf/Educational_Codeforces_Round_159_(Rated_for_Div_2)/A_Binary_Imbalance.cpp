#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int x = std::ranges::count(s, '0');
    int ok = 0;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i - 1] != s[i]) {
            ok = 1;
        }
    }
    if (x >= n - x or ok) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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
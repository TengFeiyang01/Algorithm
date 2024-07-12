#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::string s[n], t = "vika";
    int k = 0;
    for (int i = 0; i < n; ++i) 
        std::cin >> s[i];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s[j][i] == t[k]) {
                k++;
                break;
            }
        }
    }
    std::cout << (k >= 4 ? "YES\n" : "NO\n");
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
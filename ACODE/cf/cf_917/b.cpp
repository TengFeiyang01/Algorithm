#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    std::vector<int> pos(26, n);
    for (int i = 0; i < n; ++i) {
        pos[s[i] - 'a'] = std::min(pos[s[i] - 'a'], i); 
    }
    i64 ans = 0;
    for (int i = 0; i < 26; ++i) {
        ans += n - pos[i];
    }
    std::cout << ans << "\n";
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

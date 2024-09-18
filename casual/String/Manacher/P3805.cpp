#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string t, s = "#";
    std::cin >> t;
    for (auto c : t) {
        s += c;
        s += '#';
    }
    int n = s.size();
    std::vector<int> d(n);
    d[0] = 1;
    for (int i = 1, l, r = 0; i < n; ++i) {
        if (i <= r) d[i] = std::min(d[r - i + l], r - i + 1);
        while (i - d[i] >= 0 and i + d[i] < n and s[i - d[i]] == s[i + d[i]]) d[i]++;
        if (i + d[i] - 1 > r) l = i - d[i] + 1, r = i + d[i] - 1;
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans = std::max(ans, d[i] - 1);
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}

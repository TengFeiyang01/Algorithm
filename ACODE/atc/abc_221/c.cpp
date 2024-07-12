#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    int ans = 0;
    int n = s.size();
    std::vector<int> a(n + 1);
    std::iota(a.begin(), a.end(), 0);

    do {
        int x = 0, y = 0, i = 0;
        for (; a[i] != n; i++) x = x * 10 + (s[a[i]] - '0');
        ++i;
        for (; i <= n; ++i) y = y * 10 + (s[a[i]] - '0');
        ans = std::max(ans, x * y);
    } while (std::next_permutation(a.begin(), a.end()));
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}

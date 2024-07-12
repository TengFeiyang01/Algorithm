#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    std::string s, t;
    std::cin >> s >> t;
    int ans = 0;
    int n = s.size(), m = t.size();
    s = s + s;
    for (int i = 0; i < n; ++i) {
    	if (s.substr(i, m) == t) ans++;
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}

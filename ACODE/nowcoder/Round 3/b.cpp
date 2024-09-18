#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    std::string s;
    int n;
    std::cin >> s;
    int ans = inf;
    for (char c = 'a'; c <= 'z'; ++c) {
        int cur = 0;
        for (auto x : s) {
            cur += std::min((c - x + 26) % 26, (x - c + 26) % 26);
        }
        ans = std::min(ans, cur);
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}

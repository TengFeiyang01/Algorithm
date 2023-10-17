#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, m, k, a, b, s, ok = 0;
    std::cin >> n >> m >> k >> a >> b;
    s = (a + b) % 2;
    while (k--) {
        std::cin >> a >> b;
        if (s == (a + b) % 2) {
            ok = 1;
        }
    }
    std::cout << (ok ? "NO\n" : "YES\n");
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

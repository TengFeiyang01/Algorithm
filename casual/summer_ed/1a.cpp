#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, T;
    std::cin >> n >> T;
    i64 ans = 0, last = 0, cur = 0;
    for (int i = 0; i < n; ++i) {
        i64 d, b;
        std::cin >> d >> b;
        
        i64 len = d - 1 - last;
        i64 days = std::min(len, cur);

        ans += days;
        cur = cur - days + b;
        last = d - 1;
    }
    
    ans += std::min(cur, T - last);

    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}

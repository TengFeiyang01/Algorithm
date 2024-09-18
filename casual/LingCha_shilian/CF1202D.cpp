#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::string ans = "133";
    i64 m = 1;
    while ((m - 1) * m / 2 <= n) {
    	m++;
    } 
    --m;
    // 13377777...3333..7 答案为 C(cnt3, 2) + cnt7-1
    ans += std::string(n - (m - 1) * m / 2, '7');
    i64 n1 = n - m * (m - 1) / 2;
    ans += std::string(m - 2, '3');
    ans += '7';
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

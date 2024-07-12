#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    i64 m, k, a1, ak;
    std::cin >> m >> k >> a1 >> ak;
    i64 need = m % k, ans = 0;
    a1 -= need;  //少用 1 的
    m -= need;  //此时m是k的倍数

    if (a1 < 0) {  //1的不够0 需要加上
        ans -= a1;
        a1 = 0;
    }

    m = m / k;
    m -= std::min(ak, m);
    m -= std::min(a1 / k, m);
    ans += m;

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

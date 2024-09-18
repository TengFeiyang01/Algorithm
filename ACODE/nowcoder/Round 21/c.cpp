#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, p, x;
    std::cin >> n >> p >> x;
    std::vector<i64> a(n);
    i64 tot = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        tot += a[i];
    }
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        tot -= a[i];
        int need = (x - (tot % x)) % x;  // 需要的模数是need

        //有多少个这样的数      加上多余的那个           减去mod是0的    减去原本的
        ans += p / x + ((p % x) >= need ? 1 : 0) - (need == 0) - (a[i] <= p and a[i] % x == need);
        tot += a[i];
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}

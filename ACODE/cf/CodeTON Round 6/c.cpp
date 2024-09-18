#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n), l(k, n), r(k, -1);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        a[i] -= 1;
        l[a[i]] = std::min(l[a[i]], i);
        r[a[i]] = std::max(r[a[i]], i);
    }
    
    int mx = std::ranges::max(a);
    int pre = mx, tmp;
    
    //小数字肯定会包含大数字 从大到小更新

    for (int i = mx - 1; i >= 0; --i) {
        if (l[i] == n) {
            //not occur
            continue;
        }
        l[i] = std::min(l[pre], l[i]);
        r[i] = std::max(r[i], r[pre]);
        pre = i;
    }
    for (int i = 0; i < k; ++i) {
        std::cout << (l[i] == n ? 0 : 2 * (r[i] - l[i] + 1)) << " \n"[i == k - 1];
    }
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